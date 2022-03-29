#include <iostream>
#include <string>
using namespace std;

const unsigned int MAX_SIZE = 100;

struct Product
{
    string name;
    unsigned int quantity;
    float price;
};


/**
    Removes the i-th element by decreasing the currently used array size
    and overwriting every element from i position with i+1 element. If a
    incorrect index is given the function just returns;

    @param[in, out] List The given array to be deleted
    @param[in, out] sizeList The currently used length of the given array
    @param[in]      position The index of the target for deletion
*/
void RemoveElement(Product List[], unsigned int& sizeList, unsigned int position);

/**
    Prints a given array of Product
*/
void printList(Product List[], unsigned int sizeList);


/**
    Inputs two given arrays of Product.
*/
void InputData(Product List[], Product Stock[], unsigned int& sizeList, unsigned int& sizeStock);

/**
    Calculates how much will baba Penka pay at the checkout. In the process her List will change accordingly.
*/
float Shopping(Product List[], Product Stock[], unsigned int& sizeList, unsigned int& sizeStock);

int main()
{
    Product List[MAX_SIZE],  ///Baba Penka's list
            Stock[MAX_SIZE]; ///Her favorite store stock
    unsigned int sizeList, sizeStock;

    cout<<"Vuvedete kolko produkta shte kupi baba Penka [1 - "<<MAX_SIZE<<"]: ";
    cin>>sizeList;

    cout<<"Vuvedete kolko produkta ima magazina [1 - "<<MAX_SIZE<<"]: ";
    cin>>sizeStock;

    InputData(List, Stock, sizeList, sizeStock);

    cout<<"Baba Penka shte poharchi: "<<Shopping(List, Stock, sizeList, sizeStock)<<endl;;
    cout<<"Ot kaufland trqbva da si vzeme: \n";
    printList(List, sizeList);


}

void RemoveElement(Product List[], unsigned int& sizeList, unsigned int position)
{
    if(sizeList<=0||sizeList>MAX_SIZE)
    {
        return;
    }

    sizeList--;

    for(int i = position; i<sizeList; i++)
    {
        List[i] = List[i+1];
    }
}

void printList(Product List[], unsigned int sizeList)
{
    cout<<"---SPISUK----"<<endl;
    for(int i= 0; i< sizeList; i++)
    {
        cout<<"Product: "<<List[i].name<<" \\ Kolichestvo: "<<List[i].quantity<<" \\ Max Cena: "<<List[i].price<<endl;
    }
    cout<<endl;
}

void InputData(Product List[], Product Stock[], unsigned int& sizeList, unsigned int& sizeStock)
{
    if(sizeList<=0||sizeList>MAX_SIZE)
    {
        if(sizeList<=0)
        {
            cout<<"Baba Penka ne iska da prodava"<<endl;
        }
        else
        {
            cout<<"Baba Penka nqma sto ruce"<<endl;
        }

        return;
    }

    for(int i =0; i < sizeList; i++)
    {
        cout<<"Vedete ime na producta: ";
        cin.ignore();
        getline(cin, List[i].name);


        cout<<"Vuvedete kolichestvo: ";
        cin>>List[i].quantity;

        cout<<"Vuvedete cena: ";
        cin>>List[i].price;

        if(List[i].price < 0)
            List[i].price *= -1;
    }


    if(sizeStock<=0||sizeStock>MAX_SIZE)
    {
        if(sizeList<=0)
        {
            cout<<"Ne iskame magazina da e vuv falit"<<endl;
        }
        else
        {
            cout<<"Tova e magazin ne sklad"<<endl;
        }

        return;
    }

    for(int i =0; i < sizeStock; i++)
    {
        cout<<"Vedete ime na producta: ";
        cin.ignore();
        getline(cin, Stock[i].name);
        \

        cout<<"Vuvedete kolichestvo: ";
        cin>>Stock[i].quantity;

        cout<<"Vuvedete cena: ";
        cin>>Stock[i].price;

        if(List[i].price < 0)
            Stock[i].price *= -1;
    }

}



float Shopping(Product List[], Product Stock[], unsigned int& sizeList, unsigned int& sizeStock)
{
    float result = 0.0f;      ///Creating the result sum

    for(int i = 0; i < sizeList; i++)     ///Iterating baba Penka's list
    {//cout<<List[i].name<<"--"<<endl;
        for(int j = 0; j < sizeStock; j++)///Iterating the store's list
        {
            //cout<<Stock[j].name<<"//"<<endl;

            if(List[i].name == Stock[j].name) ///If there is a match

            {
                //cout<<"*";
                if(List[i].price >= Stock[j].price) ///And the price is bellow the target range
                {
                    ///If the store has above the quantity that Penka needs
                    ///it will just remove the item from her list and increase her bill
                    if(List[i].quantity<=Stock[j].quantity)
                    {
                        result += Stock[j].price * List[i].quantity;
                        RemoveElement(List, sizeList, i);
                        i--;
                    }
                    ///But if the store has less than the amount that she wants, she will just take
                    ///as much as there is
                    else if(List[i].quantity>Stock[j].quantity)
                    {
                        result += Stock[j].price * Stock[j].quantity;
                        List[i].quantity -= Stock[j].quantity;
                    }
                }

                break;
            }
        }
    }

    return result;
}
