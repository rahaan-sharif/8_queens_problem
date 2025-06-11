#include <iostream>
using namespace std;

class tree
{
private:
    int x, y;

    tree* parent;

    tree** children;

public:
    tree(int x_in, int y_in)
    {
        x=x_in;
        y=y_in;
        parent=NULL;
        children=new tree*[8];
    }
    tree(tree*& parent_in, int x_in, int y_in)
    {
        x=x_in;
        y=y_in;
        parent=parent_in;
        children=new tree*[8];
    }
    void make_root(tree* root)
    {
        root=new tree(-1, -1);
        for(int i=0; i<8; i++)
        {
            root->children[i]->make_node(root, root->children[i], i, 1);
        }
    }
    void make_node(tree*& parent, tree*& node, int x_in, int y_in)
    {
        node=new tree(parent, x_in, y_in);
        node->parent=parent;
        if(y_in>=8)
            return;
        for(int i=0; i<8; i++)

    }
    void show()
    {}

};


int main(void)
{


    return 0;
}
