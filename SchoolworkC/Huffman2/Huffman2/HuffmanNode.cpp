#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 定义哈夫曼树节点结构
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode* left, * right; // 左右子节点指针
    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// 比较器用于优先队列，确保频率最小的节点在队列前面
struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return (l->freq > r->freq);
    }
};

// 递归生成哈夫曼编码表
void generateCodes(HuffmanNode* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root) return; // 如果节点为空，返回
    if (!root->left && !root->right) { // 如果是叶子节点
        huffmanCode[root->ch] = str; // 将字符和对应的编码存入哈夫曼编码表
    }
    generateCodes(root->left, str + "0", huffmanCode); // 递归处理左子树，编码加'0'
    generateCodes(root->right, str + "1", huffmanCode); // 递归处理右子树，编码加'1'
}

// 保存哈夫曼树到文件
void saveTreeToFile(HuffmanNode* root, ofstream& outFile) {
    if (!root) {
        outFile << '#'; // 使用'#'表示空节点
        return;
    }
    outFile << root->ch; // 输出当前节点的字符
    saveTreeToFile(root->left, outFile); // 递归保存左子树
    saveTreeToFile(root->right, outFile); // 递归保存右子树
}

// 读取哈夫曼树从文件
HuffmanNode* loadTreeFromFile(ifstream& inFile) {
    char ch;
    inFile >> ch;
    if (ch == '#') return nullptr; // 如果字符是'#'，返回空节点
    HuffmanNode* node = new HuffmanNode(ch, 0); // 创建新节点
    node->left = loadTreeFromFile(inFile); // 递归读取左子树
    node->right = loadTreeFromFile(inFile); // 递归读取右子树
    return node;
}

// 主函数
int main() {
    string text;
    cout << "请输入一段英文字符：" << endl;
    getline(cin, text);

    // 统计频率
    unordered_map<char, int> freq;
    for (char ch : text) {
        if (ch != ' ') freq[ch]++;
    }

    // 创建优先队列并构建哈夫曼树
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> pq;
    for (auto pair : freq) {
        pq.push(new HuffmanNode(pair.first, pair.second)); // 将每个字符及其频率作为节点加入优先队列
    }

    while (pq.size() != 1) {
        HuffmanNode* left = pq.top(); pq.pop(); // 取出频率最小的两个节点
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* top = new HuffmanNode('$', left->freq + right->freq); // 创建一个新的内部节点，其频率为两个子节点频率之和
        top->left = left; // 设置左子节点
        top->right = right; // 设置右子节点
        pq.push(top); // 将新节点加入优先队列
    }

    HuffmanNode* root = pq.top(); // 最终的根节点即为哈夫曼树的根节点

    // 生成哈夫曼编码表
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode); // 调用递归函数生成编码表

    // 将哈夫曼树保存到文件
    ofstream treeFile("huffman_tree.txt");
    saveTreeToFile(root, treeFile);
    treeFile.close();

    // 将编码结果保存到文件
    ofstream codeFile("huffman_codes.txt");
    for (auto pair : huffmanCode) {
        codeFile << pair.first << ": " << pair.second << endl;
    }
    codeFile.close();

    // 显示编码结果
    cout << "字符的哈夫曼编码为：" << endl;
    for (auto pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 编码输入文本
    string encodedString;
    for (char ch : text) {
        if (ch != ' ') encodedString += huffmanCode[ch]; // 根据编码表对文本进行编码
    }
    cout << "编码后的字符串为：" << encodedString << endl;

    // 解码过程
    string inputSequence;
    cout << "请输入要解码的01序列：" << endl;
    cin >> inputSequence;

    // 加载哈夫曼树进行解码
    ifstream treeInFile("huffman_tree.txt");
    HuffmanNode* loadedRoot = loadTreeFromFile(treeInFile); // 从文件加载哈夫曼树
    treeInFile.close();

    string decodedString;
    HuffmanNode* current = loadedRoot;
    for (char bit : inputSequence) {
        if (bit == '0') current = current->left; // 如果位是'0'，移动到左子节点
        else current = current->right; // 如果位是'1'，移动到右子节点
        if (!current->left && !current->right) { // 如果到达叶子节点
            decodedString += current->ch; // 添加字符到解码字符串中
            current = loadedRoot; // 重置当前节点为根节点，准备解码下一个字符
        }
    }
    cout << "解码后的字符串为：" << decodedString << endl;

    return 0;
}
