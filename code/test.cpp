#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int num=0;
typedef struct Node{
	char data;
	struct Node *lchild;
	struct Node *rchild;
}Binode, *BiTree;
queue <BiTree> Q;
void CreatBiTree()
{
	char ch;
	BiTree T, N;
	while (!Q.empty()){
		scanf("%c", &ch);
		T = Q.front();
		Q.pop();
		if (ch == '\n')
			break;
		T->data = ch;
		N = (BiTree)malloc(sizeof(Binode));
		N->data = '\0';
		T->lchild = N;
		Q.push(N);
		N = (BiTree)malloc(sizeof(Binode));
		N->data = '\0';
		T->rchild = N;
		Q.push(N);
	}
}
void Visit(BiTree T)
{
	if (T->data!='#'&&T->data != '\0')
		printf("%c", T->data);
}
void PrintAoru(BiTree T, int i){

	if (T->data !='#' &&T->data != '\0'){
		int j;
		for (j = 1; j <= i; j++)
			printf("    ");
		Visit(T);
		printf("\n");
		i++;
		PrintAoru(T->lchild, i);
		PrintAoru(T->rchild, i);
	}
}void AntiPrintAoru(BiTree T, int i){

	if (T->data != '#'&&T->data != '\0'){
		int j;
		for (j = 1; j <= i; j++)
			printf("    ");
		Visit(T);
		printf("\n");
		i++;
		AntiPrintAoru(T->rchild, i);
		AntiPrintAoru(T->lchild, i);
	}
}
void PreOrderTravel(BiTree T)
{
	if (T->data != '#'&&T->data != '\0'){
		Visit(T);
		PreOrderTravel(T->lchild);
		PreOrderTravel(T->rchild);
	}
	return;
}
void AntiPreOrderTravel(BiTree T)
{
	if (T->data != '#'&&T->data != '\0'){
		Visit(T);
		AntiPreOrderTravel(T->rchild);
		AntiPreOrderTravel(T->lchild);
	}
	return;
}
void InOrderTravel(BiTree T)
{
	if (T->data != '#'&&T->data != '\0'){
		InOrderTravel(T->lchild);
		if ((T->lchild->data == '#' || T->lchild->data == '\0') && (T->rchild->data == '#' || T->rchild->data == '\0'))
			num++;
		Visit(T);
		InOrderTravel(T->rchild);
	}
	return;
}
void AntiInOrderTravel(BiTree T)
{
	if (T->data != '#'&&T->data != '\0'){
		AntiInOrderTravel(T->rchild);
		Visit(T);
		AntiInOrderTravel(T->lchild);
	}
	return;
}
void PostOrderTravel(BiTree T)
{
	if (T->data != '#'&&T->data != '\0'){
		PostOrderTravel(T->lchild);
		PostOrderTravel(T->rchild);
		Visit(T);
	}
	return;
}
void AntiPostOrderTravel(BiTree T)
{
	if (T->data != '#'&&T->data != '\0'){
		AntiPostOrderTravel(T->rchild);
		AntiPostOrderTravel(T->lchild);
		Visit(T);
	}
	return;
}
int main()
{
	BiTree Root;
	Root = (BiTree)malloc(sizeof(Binode));
	Q.push(Root);
	CreatBiTree();
	printf("BiTree\n");
	PrintAoru(Root, 0);
	printf("pre_sequence  : ");
	PreOrderTravel(Root);
	printf("\n");
	printf("in_sequence   : ");
	InOrderTravel(Root);
	printf("\n");
	printf("post_sequence : ");
	PostOrderTravel(Root);
	printf("\n");
	printf("Number of leaf: %d\n", num);
	printf("BiTree swapped\n");
	AntiPrintAoru(Root, 0);
	printf("pre_sequence  : ");
	AntiPreOrderTravel(Root);
	printf("\n");
	printf("in_sequence   : ");
	AntiInOrderTravel(Root);
	printf("\n");
	printf("post_sequence : ");
	AntiPostOrderTravel(Root);
	printf("\n");
	return 0;
}