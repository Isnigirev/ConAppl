#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

//2.//////////////////////////////////////////////////
typedef struct Node
{
    int key;
    struct Node* left;
    struct Node* right;

} TreeNode;

TreeNode* TreeInsert(TreeNode *t, int data)
{
    TreeNode *nwNode;

    nwNode = (TreeNode*) malloc(sizeof(TreeNode));

    nwNode->key = data;

    nwNode->left = NULL;

    nwNode->right = NULL;

    TreeNode *current = t;

    TreeNode *parent = t;

    if (t == NULL)
    {
        t = nwNode;
    }
    else
    {
        while (current->key != data)
        {
            parent = current;

            if (current->key > data)
            {
                current = current->left;

                if (current == NULL)
                {
                    parent->left = nwNode;

                    return t;
                }
            }
            else
            {
                current = current->right;

                if (current == NULL)
                {
                    parent->right = nwNode;

                    return t;
                }
            }
        }
    }
    return t;
}

//1.//////////////////////////////////////////////////
//Написать функцию проверяющую является ли переданное в неё бинарное дерево 
//сбалансированным:
void TreeTestBalance(TreeNode* root, int &counter)
{
    if (root)
    {
        std::cout << root->key;

        counter++;

        if (root->left || root->right)
        {
            std::cout << "(";

            if (root->left)
            {
                TreeTestBalance(root->left, counter);
            }
            else
            {
                std::cout << NULL;
            }
            std::cout << ",";

            if (root->right)
            {
                TreeTestBalance(root->right, counter);
            }
            else
            {
                std::cout << NULL;
            }
            std::cout << ")";
        }
    }
}
//1.//////////////////////////////////////////////////

void PrintTree(TreeNode* root)
{
    if (root)
    {
        std::cout << root->key;

        if (root->left || root->right)
        {
            std::cout << "(";

            if (root->left)
            {
                PrintTree(root->left);
            }
            else
            {
                std::cout <<  NULL;
            }
            std::cout << ",";

            if (root->right)
            {
                PrintTree(root->right);
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
bool TreeSearch(TreeNode* root, int value)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->key == value)
    {
        return true;
    }

    TreeNode* current = root;

    while (current->key != value)
    {
        if (value < current->key)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
        if (current == NULL)
        {
            return false;
        }
    }
}
//2.//////////////////////////////////////////////////

//1.//////////////////////////////////////////////////
//написать программу, которая:
//создаст[50] деревьев по[10000] узлов и заполнит узлы случайными 
//целочисленными значениями;

void MakeTree()
{   
    srand (time(NULL));

    TreeNode* tree1 = NULL;
    for (int i = 0; i < 10000; i++)
        tree1 = TreeInsert(tree1, rand () % 10);
    TreeNode* tree2 = NULL;
    for (int i = 0; i < 10000; i++)
        tree2 = TreeInsert(tree1, rand() % 10);
    TreeNode* tree3 = NULL;
    for (int i = 0; i < 10000; i++)
        tree3 = TreeInsert(tree3, rand() % 10);
    TreeNode* tree4 = NULL;
    for (int i = 0; i < 10000; i++)
        tree4 = TreeInsert(tree4, rand() % 10);
    TreeNode* tree5 = NULL;
    for (int i = 0; i < 10000; i++)
        tree5 = TreeInsert(tree5, rand() % 10);
    TreeNode* tree6 = NULL;
    for (int i = 0; i < 10000; i++)
        tree6 = TreeInsert(tree6, rand() % 10);
    TreeNode* tree7 = NULL;
    for (int i = 0; i < 10000; i++)
        tree7 = TreeInsert(tree7, rand() % 10);
    TreeNode* tree8 = NULL;
    for (int i = 0; i < 10000; i++)
        tree8 = TreeInsert(tree8, rand() % 10);
    TreeNode* tree9 = NULL;
    for (int i = 0; i < 10000; i++)
        tree9 = TreeInsert(tree9, rand() % 10);
    TreeNode* tree10 = NULL;
    for (int i = 0; i < 10000; i++)
        tree10 = TreeInsert(tree10, rand() % 10);

    TreeNode* tree11 = NULL;
    for (int i = 0; i < 10000; i++)
        tree11 = TreeInsert(tree11, rand() % 20);
    TreeNode* tree12 = NULL;
    for (int i = 0; i < 10000; i++)
        tree12 = TreeInsert(tree11, rand() % 20);
    TreeNode* tree13 = NULL;
    for (int i = 0; i < 10000; i++)
        tree13 = TreeInsert(tree13, rand() % 20);
    TreeNode* tree14 = NULL;
    for (int i = 0; i < 10000; i++)
        tree14 = TreeInsert(tree14, rand() % 20);
    TreeNode* tree15 = NULL;
    for (int i = 0; i < 10000; i++)
        tree15 = TreeInsert(tree15, rand() % 20);
    TreeNode* tree16 = NULL;
    for (int i = 0; i < 10000; i++)
        tree16 = TreeInsert(tree16, rand() % 20);
    TreeNode* tree17 = NULL;
    for (int i = 0; i < 10000; i++)
        tree17 = TreeInsert(tree17, rand() % 20);
    TreeNode* tree18 = NULL;
    for (int i = 0; i < 10000; i++)
        tree18 = TreeInsert(tree18, rand() % 20);
    TreeNode* tree19 = NULL;
    for (int i = 0; i < 10000; i++)
        tree19 = TreeInsert(tree19, rand() % 20);
    TreeNode* tree20 = NULL;
    for (int i = 0; i < 10000; i++)
        tree20 = TreeInsert(tree20, rand() % 20);

    TreeNode* tree21 = NULL;
    for (int i = 0; i < 10000; i++)
        tree21 = TreeInsert(tree21, rand() % 30);
    TreeNode* tree22 = NULL;
    for (int i = 0; i < 10000; i++)
        tree22 = TreeInsert(tree21, rand() % 30);
    TreeNode* tree23 = NULL;
    for (int i = 0; i < 10000; i++)
        tree23 = TreeInsert(tree23, rand() % 30);
    TreeNode* tree24 = NULL;
    for (int i = 0; i < 10000; i++)
        tree24 = TreeInsert(tree24, rand() % 30);
    TreeNode* tree25 = NULL;
    for (int i = 0; i < 10000; i++)
        tree25 = TreeInsert(tree25, rand() % 30);
    TreeNode* tree26 = NULL;
    for (int i = 0; i < 10000; i++)
        tree26 = TreeInsert(tree26, rand() % 30);
    TreeNode* tree27 = NULL;
    for (int i = 0; i < 10000; i++)
        tree27 = TreeInsert(tree27, rand() % 30);
    TreeNode* tree28 = NULL;
    for (int i = 0; i < 10000; i++)
        tree28 = TreeInsert(tree28, rand() % 30);
    TreeNode* tree29 = NULL;
    for (int i = 0; i < 10000; i++)
        tree29 = TreeInsert(tree29, rand() % 30);
    TreeNode* tree30 = NULL;
    for (int i = 0; i < 10000; i++)
        tree30 = TreeInsert(tree30, rand() % 30);

    TreeNode* tree31 = NULL;
    for (int i = 0; i < 10000; i++)
        tree31 = TreeInsert(tree31, rand() % 40);
    TreeNode* tree32 = NULL;
    for (int i = 0; i < 10000; i++)
        tree32 = TreeInsert(tree31, rand() % 40);
    TreeNode* tree33 = NULL;
    for (int i = 0; i < 10000; i++)
        tree33 = TreeInsert(tree33, rand() % 40);
    TreeNode* tree34 = NULL;
    for (int i = 0; i < 10000; i++)
        tree34 = TreeInsert(tree34, rand() % 40);
    TreeNode* tree35 = NULL;
    for (int i = 0; i < 10000; i++)
        tree35 = TreeInsert(tree35, rand() % 40);
    TreeNode* tree36 = NULL;
    for (int i = 0; i < 10000; i++)
        tree36 = TreeInsert(tree36, rand() % 40);
    TreeNode* tree37 = NULL;
    for (int i = 0; i < 10000; i++)
        tree37 = TreeInsert(tree37, rand() % 40);
    TreeNode* tree38 = NULL;
    for (int i = 0; i < 10000; i++)
        tree38 = TreeInsert(tree38, rand() % 40);
    TreeNode* tree39 = NULL;
    for (int i = 0; i < 10000; i++)
        tree39 = TreeInsert(tree39, rand() % 40);
    TreeNode* tree40 = NULL;
    for (int i = 0; i < 10000; i++)
        tree40 = TreeInsert(tree40, rand() % 40);

    TreeNode* tree41 = NULL;
    for (int i = 0; i < 10000; i++)
        tree41 = TreeInsert(tree41, rand() % 50);
    TreeNode* tree42 = NULL;
    for (int i = 0; i < 10000; i++)
        tree42 = TreeInsert(tree41, rand() % 50);
    TreeNode* tree43 = NULL;
    for (int i = 0; i < 10000; i++)
        tree43 = TreeInsert(tree43, rand() % 50);
    TreeNode* tree44 = NULL;
    for (int i = 0; i < 10000; i++)
        tree44 = TreeInsert(tree44, rand() % 50);
    TreeNode* tree45 = NULL;
    for (int i = 0; i < 10000; i++)
        tree45 = TreeInsert(tree45, rand() % 50);
    TreeNode* tree46 = NULL;
    for (int i = 0; i < 10000; i++)
        tree46 = TreeInsert(tree46, rand() % 50);
    TreeNode* tree47 = NULL;
    for (int i = 0; i < 10000; i++)
        tree47 = TreeInsert(tree47, rand() % 50);
    TreeNode* tree48 = NULL;
    for (int i = 0; i < 10000; i++)
        tree48 = TreeInsert(tree48, rand() % 50);
    TreeNode* tree49 = NULL;
    for (int i = 0; i < 10000; i++)
        tree49 = TreeInsert(tree49, rand() % 50);
    TreeNode* tree50 = NULL;
    for (int i = 0; i < 10000; i++)
        tree50 = TreeInsert(tree50, rand() % 50);

    //рассчитать, какой процент из созданных деревьев является сбалансированными.

    int counterleft = 0, counterright = 0, counter = 0;

    TreeTestBalance(tree1->left, counterleft);
    TreeTestBalance(tree1->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree2->left, counterleft);
    TreeTestBalance(tree2->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree3->left, counterleft);
    TreeTestBalance(tree3->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree4->left, counterleft);
    TreeTestBalance(tree4->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree5->left, counterleft);
    TreeTestBalance(tree5->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree6->left, counterleft);
    TreeTestBalance(tree6->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree7->left, counterleft);
    TreeTestBalance(tree7->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree8->left, counterleft);
    TreeTestBalance(tree8->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree9->left, counterleft);
    TreeTestBalance(tree9->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree10->left, counterleft);
    TreeTestBalance(tree10->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree12->left, counterleft);
    TreeTestBalance(tree12->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree13->left, counterleft);
    TreeTestBalance(tree13->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree14->left, counterleft);
    TreeTestBalance(tree14->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree16->left, counterleft);
    TreeTestBalance(tree16->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree17->left, counterleft);
    TreeTestBalance(tree17->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree18->left, counterleft);
    TreeTestBalance(tree18->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree19->left, counterleft);
    TreeTestBalance(tree19->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree20->left, counterleft);
    TreeTestBalance(tree20->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree21->left, counterleft);
    TreeTestBalance(tree21->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree23->left, counterleft);
    TreeTestBalance(tree23->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree24->left, counterleft);
    TreeTestBalance(tree24->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree25->left, counterleft);
    TreeTestBalance(tree25->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree26->left, counterleft);
    TreeTestBalance(tree26->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree27->left, counterleft);
    TreeTestBalance(tree27->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree28->left, counterleft);
    TreeTestBalance(tree28->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree29->left, counterleft);
    TreeTestBalance(tree29->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree30->left, counterleft);
    TreeTestBalance(tree30->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree31->left, counterleft);
    TreeTestBalance(tree31->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree32->left, counterleft);
    TreeTestBalance(tree32->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree33->left, counterleft);
    TreeTestBalance(tree33->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree34->left, counterleft);
    TreeTestBalance(tree34->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree35->left, counterleft);
    TreeTestBalance(tree35->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree36->left, counterleft);
    TreeTestBalance(tree36->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree37->left, counterleft);
    TreeTestBalance(tree37->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree38->left, counterleft);
    TreeTestBalance(tree38->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree39->left, counterleft);
    TreeTestBalance(tree39->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree40->left, counterleft);
    TreeTestBalance(tree40->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree41->left, counterleft);
    TreeTestBalance(tree41->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree42->left, counterleft);
    TreeTestBalance(tree42->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree43->left, counterleft);
    TreeTestBalance(tree43->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree44->left, counterleft);
    TreeTestBalance(tree44->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree45->left, counterleft);
    TreeTestBalance(tree45->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree46->left, counterleft);
    TreeTestBalance(tree46->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree47->left, counterleft);
    TreeTestBalance(tree47->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree48->left, counterleft);
    TreeTestBalance(tree48->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree49->left, counterleft);
    TreeTestBalance(tree49->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    TreeTestBalance(tree50->left, counterleft);
    TreeTestBalance(tree50->right, counterright);
    (counterleft == counterright) ? counter++ : 0;
    counterleft = 0, counterright = 0;

    int a = 50;

    double c = 0;

    c = (double(counter) / a);

    c *= 100;

    std::cout << "\nПроцент созданных сбалансированных деревьев->" << c << "%" << std::endl;
}

//1.//////////////////////////////////////////////////

int main()
{
    setlocale(LC_ALL, "Ru");

    TreeNode* tree = NULL;

    tree = TreeInsert(tree, 10);

    TreeInsert(tree, 1);
    TreeInsert(tree, 2);
    TreeInsert(tree, 3);
    TreeInsert(tree, 11);
    TreeInsert(tree, 12);
    TreeInsert(tree, 13);

    PrintTree(tree);

//1.////////////////////////////////////////////////
    std::cout << "\n";

    int counterleft = 0, counterright = 0;
    std::cout << "TestBalanceLeft->";
    TreeTestBalance(tree->left, counterleft);
    std::cout << "\tTestBalanceRight->";
    TreeTestBalance(tree->right, counterright);

    std::cout << "\nTestBalance->"; (counterleft == counterright) ? (std::cout << "true") : (std::cout << "false");

    //Создание 50 деревьев по 10000 узлов в каждом)

    std::cout << "\n";

    MakeTree();
    MakeTree();
    MakeTree();
    MakeTree();
    MakeTree();

//2.////////////////////////////////////////////////

    std::cout << "\n";

    TreeInsert(tree, 8);
    TreeInsert(tree, 19);
    TreeInsert(tree, 5);
    TreeInsert(tree, 9);
    TreeInsert(tree, 16);
    TreeInsert(tree, 21);

    PrintTree(tree);

    std::cout << "\n 8 in tree->" << TreeSearch(tree, 8);
    std::cout << "\n 100 in tree->" << TreeSearch(tree, 100);

    return 0;
}   