#ifndef BinaryTree_BinaryTree_h
#define BinaryTree_BinaryTree_h
#include<vector>
#include "BNode.h"

using namespace std;


    template <class T>
    class BinaryTree {
    private:
        BNode<T> * root = nullptr;

    public:
        BinaryTree() {}
        virtual ~BinaryTree();

        bool empty();

        void clear();
        void clear(BNode<T> * node);

        BNode<T> * getRoot() const;
        void setRoot(BNode<T> * node);

        bool insert(BNode<T> * parent, T value);
        bool insert(BNode<T> * parent, BNode<T> * value);

        void preOrder() const;
        void preOrder(BNode<T> * node) const;

        void inOrder() const;
        void inOrder(BNode<T> * node) const;

        void postOrder() const;
        void postOrder(BNode<T> * node) const;

        void isLeaf() const;
        void isLeaf(BNode<T> * node) const;

        void ancestors(BNode<T> * node) const;
        bool isBrother(BNode<T> * node) const;
        void cousins(BNode<T> * node) const;
        bool isAncestor(BNode<T> * node) const;
        void sons(BNode<T> * node) const;
        void deep(BNode<T> * node) const;

        void sumaDescendientes() const;
        void sumaDescendientes (BNode<T> * node) const;

        void reflexion() const;
        void reflexion(BNode<T> * node) const;

        bool esSimetrico();
        std::vector<T> getPrimos(std::vector<T> primos, BNode<T> * node, int nivAct, int nivel);

    };


    template<class T>
    bool BinaryTree<T>::esSimetrico()
    {
        std::vector<T> primos;
        int nivel = 1;
        bool esSim = true;

        do
        {
            primos.clear();
            primos = this->getPrimos(primos,root,0,nivel);

            if (!primos.empty())
            {
                cout << endl;
                if (primos.size() % 2 == 0)
                {
                    for (int i = 0; i < primos.size()/2; i++){
                        if (primos[i] != primos[i+ primos.size()/2])
                            esSim = false;
                    }
                }else{
                    esSim = false;
                }
            }

            nivel++;

        }while (!primos.empty());

        return esSim;
    }




    template<class T>
    std::vector<T> BinaryTree<T>::getPrimos(std::vector<T> primos, BNode<T> * node, int nivAct, int nivel)
    {
        if (node && nivAct < nivel) {

            std::vector<T> lef = getPrimos(primos,node->getLeft(),(nivAct+1),nivel);
            std::vector<T> rig = getPrimos(primos,node->getRight(),(nivAct+1),nivel);
            if (!lef.empty()) primos.insert( primos.end(), lef.begin(), lef.end() );
            if (!rig.empty()) primos.insert( primos.end(), rig.begin(), rig.end() );
        }else{
            if (nivel == nivAct && node)
                primos.push_back(node->getInfo());
        }

        return primos;

    }








    template<class T>
    void BinaryTree<T>::reflexion() const
    {
        reflexion(root);
    }

    template<class T>
    void BinaryTree<T>::reflexion(BNode<T> * node) const
    {
        if (node) {
            reflexion(node->getLeft());
            reflexion(node->getRight());

            //Intercambiar derecho por izquierdo
            BNode<T> *aux = node->getRight();
            node->setRight(node->getLeft());
            node->setLeft(aux);
        }

    }


    template <class T>
    void BinaryTree<T>::sumaDescendientes() const
    {
        sumaDescendientes(root);
    }
    template <class T>
    void BinaryTree<T>::sumaDescendientes(BNode<T> * node) const
    {
        if (node) {
            sumaDescendientes(node->getLeft());
            sumaDescendientes(node->getRight());

            int suma = node->getInfo();
            if (node->getLeft()) suma += node->getLeft()->getInfo();
            if (node->getRight()) suma += node->getRight()->getInfo();

            node->setInfo(suma);
        }

    }

    template <class T>
    BinaryTree<T>::~BinaryTree()
    {
        clear();
    }

    template <class T>
    bool BinaryTree<T>::empty()
    {
        return root == nullptr;
    }

    template <class T>
    void BinaryTree<T>::clear()
    {
        clear(root);
    }

    template <class T>
    void BinaryTree<T>::clear(BNode<T> * node)
    {
        if (node) {
            clear(node->getLeft());
            clear(node->getRight());

            delete node;
        }
    }

    template <class T>
    BNode<T> * BinaryTree<T>::getRoot() const
    {
        return root;
    }

    template <class T>
    void BinaryTree<T>::setRoot(BNode<T> * node)
    {
        if (!empty()) {
            node->setLeft(root);
            root->setParent(node);
            root = node;
        }
        else {
            root = node;
        }
    }

    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, T value)
    {
        BNode<T> * node = new BNode<T>(value);
        bool inserted = insert(parent, node);

        if (!inserted) delete node;

        return inserted;
    }

    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, BNode<T> * value)
    {
        bool inserted = false;

        if (empty() || !parent) {
            setRoot(value);
            inserted = true;
        }
        else {
            if (!parent->getLeft()) {
                parent->setLeft(value);
                value->setParent(parent);
                inserted = true;
            }
            else if (!parent->getRight()) {
                parent->setRight(value);
                value->setParent(parent);
                inserted = true;
            }
        }

        return inserted;
    }

    template <class T>
    void BinaryTree<T>::preOrder() const
    {
        preOrder(root);
    }

    template <class T>
    void BinaryTree<T>::preOrder(BNode<T> * node) const
    {
        if (node) {
            /* Procesar el nodo */
            std::cout << *node << std::endl;

            /* Invocar a los hijos */
            preOrder(node->getLeft());
            preOrder(node->getRight());

        }
    }

    template <class T>
    void BinaryTree<T>::inOrder() const
    {
        inOrder(root);
    }

    template <class T>
    void BinaryTree<T>::inOrder(BNode<T> * node) const
    {
        if (node) {

            /* Invocar al hijo izquierdo */
            inOrder(node->getLeft());

            /* Procesar el nodo */
            std::cout << *node << std::endl;

            /* Invocar al hijo derecho */
            inOrder(node->getRight());
        }
    }

    template <class T>
    void BinaryTree<T>::postOrder() const
    {
        postOrder(root);
    }

    template <class T>
    void BinaryTree<T>::postOrder(BNode<T> * node) const
    {
        if (node) {
            /* Invocar a los hijos */
            postOrder(node->getLeft());
            postOrder(node->getRight());

            /* Procesar el nodo */
            std::cout << *node << std::endl;
        }
    }

    template <class T>
    void BinaryTree<T>::isLeaf() const
    {
        isLeaf(root);
    }

    template <class T>
    void BinaryTree<T>::isLeaf(BNode<T> * node) const
    {
        if (node) {
            if (!node->getLeft() && !node->getRight()) {
                std::cout << *node << std::endl;
            }
            else {
                isLeaf(node->getLeft());
                isLeaf(node->getRight());
            }
        }
    }

    template <class T>
    void BinaryTree<T>::ancestors(BNode<T> * node) const
    {
        if (node) {
            std::cout << *node << " -> ";
            ancestors(node->getParent());
        }
    }


#endif
