#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Record
{
public:
Record() {}
Record(string name, string description) { Name = name; Description = description; }
string GetKey() {return Name; }
void SetKey(string key) { Name = key; }
int GetHash(int M) 
{
    string key = GetKey();
    
    int index = 0;
    
    for (int i = 0; i< key.size(); i++)
    {
        index += (int)key[i];
    }
    
    return index % M;
}

void Print()
{
    cout<<Name<<" "<<Description<<endl;
}
private:
string Name;
string Description;
};

template<class T, class K>
class HashTable
{
public:
HashTable(int M) { table.resize(M); }
void Insert(T rec)
{
    int index = rec.GetHash(table.size());
    table[index].push_back(rec);
}

void PrintHashTable()
{
    for (int i=0; i<table.size(); i++)
    {
        for (int j=0; j< table[i].size();j++)
        {
            cout<<table[i][j].GetKey()<<" ";
        }
        cout<<endl;
    }
}

T* Find(K key)
{
    T tempRec;
    tempRec.SetKey(key);
    int index = tempRec.GetHash(table.size());
    
    for(int i=0; i<table[index].size(); i++)
    {
        if (table[index][i].GetKey() == key)
        {
            return &table[index][i];
        }
    }
    
    return NULL;
}

private:
vector< vector<T> > table;
};

int main()
{
   HashTable<Record, string> ht(50);
   
   string s = "";
   
   for (int i=0;i<26; i++)
   {
       s += (char)('A'+i);
       for (int j=0; j< 26; j++)
       {
           s+=(char)('A'+j);
           ht.Insert(*(new Record(s,s)));
           s = s.substr(0, s.size()-1);
       }
       
       
       s="";
   }
   
   ht.PrintHashTable();
   
   Record* pRec = ht.Find("EF");
   
   if (NULL != pRec)
   {
       pRec->Print();
   }
   
   return 0;
}

