#include <iostream>
using namespace std;
#define dimentions 8

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
        children=new tree*[dimentions];
    }
    tree(tree*& parent_in, int x_in, int y_in)
    {
        x=x_in;
        y=y_in;
        parent=parent_in;
        children=new tree*[dimentions];
    }
    void make_root(tree*& root)
    {
        cout<<"make root function: \n";
        root=new tree(-1, -1);
        for(int i=0; i<dimentions; i++)
        {
            root->children[i]->make_node(root, root->children[i], i, 0);
            cout<<"------------\n";
        }
    }
    void make_node(tree*& parent, tree*& node, int x_in, int y_in)
    {
        if(y_in>=dimentions  || parent->x==x_in ||
           parent->x==x_in-1 || parent->x==x_in+1)
            return;

        node=new tree(parent, x_in, y_in);
        node->parent=parent;

        cout<<"make node function:  ("<<node->x<<","<<node->y<<")\n";

        for(int i=0; i<dimentions; i++)
        {
            node->children[i]->make_node(node, node->children[i], i, node->y+1);
        }
    }
    void show(tree*& root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<"("<<root->x<<","<<root->y<<") -> ";

        for(int i=0; i<dimentions; i++)
        {
            root->children[i]->show(root->children[i]);
        }
    }
};


int main(void)
{
    cout<<"main function\n";
    tree* root=NULL;
    root->make_root(root);
    cout<<endl<<endl;
    root->show(root);


    return 0;
}
