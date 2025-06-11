#include <iostream>
using namespace std;
#define dimentions 8

class linked_list
{
private:
    int x, y;
    linked_list* next;
public:
    linked_list(int x_in, int y_in)
    {
        x=x_in;
        y=y_in;
        next=NULL;
    }
    void make_node(linked_list*& start, int x_in, int y_in)
    {
        if(start==NULL)
        {
            start=new linked_list(x_in, y_in);
        }
        else
        {
            linked_list* tmp_ll=start;
            while(tmp_ll->next!=NULL)
            {
                tmp_ll=tmp_ll->next;
            }
            tmp_ll->next=new linked_list(x_in, y_in);
        }
    }
    void show(linked_list* start)
    {
        cout<<"(x,y):"<<endl;
        start=start->next;
        if(start==NULL)
        {
            cout<<"null list\n";
            return;
        }
        while(start->next!=NULL)
        {
            cout<<"("<<start->x<<","<<start->y<<") -> ";
            start=start->next;
        }
        cout<<"("<<start->x<<","<<start->y<<")\n";
    }
};

linked_list* start_ll=NULL;

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
        root=new tree(-1, -1);
        for(int i=0; i<dimentions; i++)
        {
            if(root->children[i]->make_node(root, root->children[i], i, 0))
            {
                start_ll->make_node(start_ll, i, 0);
                return;
            }
        }
    }
    int make_node(tree*& parent, tree*& node, int x_in, int y_in)
    {
        if(y_in>=dimentions)
        {
            return 1;
        }

        tree* tmp_tree=parent;
        while(tmp_tree!=NULL && tmp_tree->x!=-1 && tmp_tree->y!=-1)
        {
            if(tmp_tree->x - x_in  == tmp_tree->y - y_in)
            {
                return 0;
            }
            else if(tmp_tree->x - x_in  == -(tmp_tree->y - y_in))
            {
                return 0;
            }
            else if(tmp_tree->x==x_in  ||  tmp_tree->y==y_in)
            {
                return 0;
            }
            tmp_tree=tmp_tree->parent;
        }

        node=new tree(parent, x_in, y_in);
        node->parent=parent;

        for(int i=0; i<dimentions; i++)
        {
            if(node->children[i]->make_node(node, node->children[i], i, node->y+1))
            {
                start_ll->make_node(start_ll, i, node->y+1);
                return 1;
            }
        }
        return 0;
    }
};


int main(void)
{
    tree* root=NULL;
    root->make_root(root);
    start_ll->show(start_ll);


    return 0;
}
