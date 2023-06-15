#include<iostream>
#include<string.h>
using namespace std;
class node
{
    public:
        string keyword,meaning;
        node *left, *right;
        node()
        {
            left=right=NULL;
        }
};
node *insert(string keyword, string meaning, node *root)
{
    node *current_node=new node;
    current_node->keyword=keyword;
    current_node->meaning=meaning;
    if(root==NULL)
    {
        root=current_node;
    }
    else
    {
        node *ptr=root;
        while(1)
        {
            if(current_node->keyword < ptr->keyword)
            {
                if(ptr->left!=NULL)
                {
                    ptr=ptr->left;
                }
                else
                {
                    ptr->left=current_node;
                    break;
                }
            }
            else
            {
                if(ptr->right!=NULL)
                {
                    ptr=ptr->right;
                }
                else
                {
                    ptr->right=current_node;
                    break;
                }
            }
        }
    }
    return root;
}
void ascending(node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    ascending(ptr->left);
    cout<<ptr->keyword<<"  "<<ptr->meaning<<endl;
    ascending(ptr->right);
    
}
node *delet(string keyword , node *root)
{
    node *current=root;
    node *parent=NULL;
    node *successor=NULL;
    while(current!=NULL && current->keyword!=keyword)
    {
        parent=current;
        if(current->keyword > keyword)
        {
            current=current->left;
        }
        else
        {
            current=current->right;
        }
    }
    if(current!=NULL)
    {
        if(current->left==NULL && current->right==NULL)
        {
            if(parent!=NULL)
            {
                if(parent->left==current)
                {
                    parent->left=NULL;
                }
                else
                {
                    parent->right=NULL;
                }
                delete current;
                
            }
            else
            {
                delete current;
                root==NULL;
                
            }
        }
        else if(current->right==NULL)
        {
            if(current==root)
            {
                root=current->left;
                delete current;
                 
            }
            else if(parent->left==current)
            {
                parent->left=current->left;
            }
            else
            {
                parent->right=current->left;
            }
            delete current;
            
        }
        else if(current->left==NULL)
        {
            if(current==root)
            {
                root=current->right;
                delete current;
                
            }
            else if(parent->left==current)
            {
                parent->left=current->right;
            }
            else
            {
                parent->right=current->right;
            }
            delete current;
            
        }
        else
        {
            successor=current->right;
            while(successor->left!=NULL)
            {
                successor=successor->left;
            }
            string successor_keyword=successor->keyword;
            string successor_meaning=successor->meaning;
            current->right=delet(successor_keyword,current->right);
            current->keyword=successor_keyword;
            current->meaning=successor_meaning;
        }
    }
    return root;
}
node *search(string keyword, node* ptr)
{
    if(ptr==NULL)
    {
        return 0;
    }
    if(ptr->keyword==keyword)      
    {
        return ptr;
    }
    else
    {
        while(1)
        {
            if(keyword < ptr->keyword)
            {
                if(ptr->keyword != keyword)
                {
                    ptr=ptr->left;
                }
                else
                {
                    return ptr;
                    break;
                }
            }
            else
            {
                if(ptr->keyword != keyword)
                {
                    ptr=ptr->right;
                }
                else
                {
                    return ptr;
                    break;
                }
            }
        }
    }
}
void descending(node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    descending(ptr->right);
    cout<<ptr->keyword<<"  "<<ptr->meaning<<endl;
    descending(ptr->left);
}

int main()
{
    string keyword,meaning;
    node *root=NULL;
    int ch;
    node *ptr;
    while(1)
    {
        cout<<"Menu: "<<endl;
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Update"<<endl;
        cout<<"4. Search"<<endl;
        cout<<"5. Ascending"<<endl;
        cout<<"6. Descending"<<endl;
        cout<<"Enter the choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                {
                    cout<<"Enter the keyword to insert: ";
                    cin.ignore();
                    getline(cin,keyword);
                    cout<<"Enter the meaning to insert: ";
                    getline(cin,meaning);
                    root=insert(keyword,meaning, root);
                    cout<<"Keyword is inserted"<<endl<<endl;
                }
                break;
            case 2:
                {
                    cout<<"Enter the keyword to delete: ";
                    cin.ignore();
                    getline(cin,keyword);
                    root=delet(keyword,root);
                    cout<<"Keyword is deleted"<<endl<<endl;
                }
                break;
            case 4:
                {
                    cout<<"Enter the keyword : ";
                    cin.ignore();
                    getline(cin,keyword);
                    ptr=search(keyword, root);
                    cout<<"Meaning is: "<<ptr->meaning<<endl;
                }
                break;
            case 3:
                {
                    cout<<"Enter the keyword to update: ";
                    cin.ignore();
                    getline(cin,keyword);
                    ptr=search(keyword,root);
                    if(ptr==NULL)
                    {
                        cout<<"Node not found";
                    }
                    else
                    {
                        cout<<"Enter the new meaning: ";
                        getline(cin,meaning);
                        ptr->meaning=meaning;
                }
                break;
            case 5:
                {
                    cout<<"Ascending order is: "<<endl;
                    ascending(root);
                }
                break;
            case 6:
                {
                    cout<<"Descending order is: "<<endl;
                    descending(root);
                }
        }
        }
    }
}