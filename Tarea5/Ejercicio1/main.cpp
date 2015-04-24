using namespace std;

template <typename T>
void sumTree(BinaryTree<T> * original, BinaryTree<T> * sum);

template <typename T>
void sumTree(BinaryTree<T> * original, BinaryTree<T> * sum, BNode<T> *nodo, BNode<T> * wSum);


int main()
{
    
    BinaryTree<int> * tree = new BinaryTree<int>;
    BinaryTree<int> * sumtree = new BinaryTree<int>;
    
    tree->insert(1, nullptr);
    tree->insert(3, 1);
    tree->insert(784, 2);
    tree->insert(12, 2);
    
    
    sumTree(tree, sumTree);
    
    cout << "Bienvenido al Sumador de Arboles T9-321890: " << *tree << endl;
    cout << "Datos: " << *tree << endl;
    cout << "Suma: " << *sumTree << endl;
    
    return 0;
}

template <typename T>
void sumTree(BinaryTree<T> * original, BinaryTree<T> * sum) {
    sumTree<T>(original, sum, original->getRoot(), nullptr);
}

template <typename T>
void sumTree(BinaryTree<T> * original, BinaryTree<T> * sum, BNode<T> *nOriginal, BNode<T> *tSum) {
    if (nOriginal) {
        wSum = sum->insert((original->efficientSum(nOriginal)), tSum);
        sumTree(original, sum, nOriginal->getLeft(), tSum);
        sumTree(original, sum, nOriginal->getRight(), tSum);
    }
}
