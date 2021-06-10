#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

class m_compare{
public:
    bool operator()(pair<string,int> p1,pair<string,int> p2){
        return p1.second < p2.second ;
    }
};
int main()
{

    cout<<"************************************************************************************"<<endl;
    cout<<"                                    SPLITWISE APP                                   "<<endl;
    cout<<"************************************************************************************"<<endl;
    cout<<endl;

    int no_of_persons;
    cout<<"Enter No of Persons : " <<endl;
    cin>>no_of_persons;
    cout<<endl;

    int no_of_transactions;
    cout<<"Enter No of Transactions : "<<endl;
    cin>>no_of_transactions;

    cout<<endl;

    int temp = no_of_transactions;

    map<string,int> net;

    while(temp--)
    {
        string p1,p2;
        int x;
        cout<<"Enter Transaction detail (Person1 will pay x amount to person2 ) "<<endl;
        cout<<"Person1: ";
        cin>>p1;
        cout<<"Person2: ";
        cin>>p2;
        cout<<"Amount: ";
        cin>>x;

        net[p1] -= x;
        net[p2] += x;

    }
    cout<<endl;
    cout<<"Simplified Transactions "<<endl;
    cout<<endl;
    multiset<pair<string,int>,m_compare> m;
    for(auto p: net)
    {
        string person = p.first;
        int amount = p.second;

        if(net[person] != 0)
        {
            m.insert(make_pair(person,amount));
        }
    }


    int reduced_transaction = 0;

    while(!m.empty())
    {
        auto low = m.begin();
        auto high = prev(m.end());

        m.erase(low);
        m.erase(high);

        int debit = low->second;
        string debit_person = low->first;

        int credit = high->second;
        string credit_person = high->first;
        int settled = min(-debit,credit);

        debit += settled;
        credit -= settled;

        cout<<debit_person<<" will pay "<<settled<<" to "<<credit_person<<endl;

        if(debit != 0)
        {
            m.insert(make_pair(debit_person,debit));
        }

        if(credit != 0)
        {
            m.insert(make_pair(credit_person,credit));
        }
        reduced_transaction++;
    }

    cout<<"Settled Transactions : "<<reduced_transaction<<endl;


    return 0;
}
