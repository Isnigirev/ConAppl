#include <iostream>

//2.//////////////////////////////////////////////////
typedef struct Node
{
    int iKey;
    struct Node* left;
    struct Node* right;

} BinTreeIntNode;

FILE* file;

int iX = 0, iNL = 0, iNR = 0;

BinTreeIntNode* BalanceTree(int iN)
{
    BinTreeIntNode* nwNode;
    iX, iNL, iNR;

    if (iN == 0)
    {
        return nullptr;
    }
    else
    {
        fscanf_s(file, "%d", &iX);

        iNL = iNL / 2;
        iNR = iN - iNL - 1;
        nwNode = (BinTreeIntNode*)malloc(sizeof(BinTreeIntNode));
        nwNode->iKey = iX;
        nwNode->left = BalanceTree(iNL);
        nwNode->right = BalanceTree(iNR);
    }
    return nwNode;
}

void printBinTree(BinTreeIntNode* root)
{
    if (root)
    {
        std::cout << root->iKey;

        if (root->left || root->right)
        {
            std::cout << "(";
            if (root->left)
            {
                printBinTree(root->left);
            }
            else
            {
                std::cout <<  NULL;
            }
            std::cout << ",";
            if (root->right)
            {
                printBinTree(root->right);
            }
            else
            {
                std::cout << NULL;
            }
            std::cout << ")";
        }
    }
}
//2.//////////////////////////////////////////////////
//Написать рекурсивную функцию бинарного поиска в 
//дереве хранящемся в узлах, а не в массиве.
bool BinTreeSearch(BinTreeIntNode* root, int iValue)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->iKey == iValue)
    {
        return true;
    }
    BinTreeIntNode* current = root;
    while (current->iKey != iValue)
    {
        if (iValue < current->iKey)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
        if (current == nullptr)
        {
            return false;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    BinTreeIntNode* tree = nullptr;

    fopen_s(&file, "balance.txt", "r+");

    if (file == nullptr)
    {
        std::cout << "Не удалось открыть файл" << std::endl;
        return 1;
    }

    const int count = 15;

    tree = BalanceTree(count);

    return 0;
}   