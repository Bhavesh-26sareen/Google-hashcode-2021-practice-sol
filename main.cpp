#include<bits/stdc++.h>
using namespace std;

bool sortby2(pair<int,int> &a, pair<int,int> &b) 
{
    return (a.second > b.second);
}

void solve(){
    int IgdCnt,M,T2,T3,T4,D=0;
    string Ignd;
    // Taking input
    cin >> M >> T2 >> T3 >> T4;
    vector<pair<int,int>> pzzIgdCount(M);
    unordered_map<int,vector<string>> pzzIgdList(M);
    for(int i = 0; i < M; i++){
        cin >> IgdCnt;
        pzzIgdCount[i] = {i,IgdCnt};
        for(int j = 0; j < IgdCnt; j++)
        {
            cin >> Ignd;
            pzzIgdList[i].push_back(Ignd);
        }
    }
    
    //vector<pair<int,vector<int>>> pzzDelList;
    sort(pzzIgdCount.begin(),pzzIgdCount.end(),sortby2);
    // Make Initial solution
    int Tsize;
    int sc4=0 , sc3=0,sc2=0 ;
    int tm4=0 , tm3=0,tm2=0 ;
    int aks = 0 ;
    vector<int> four , three , two ;
   
            int a = T4*4 ;
            if(M % 4 > 0)
            {
               a = a - 4 ;
            }
            while(a>0 && M > 0)
            {
                pair<int,int> temp;
                temp = pzzIgdCount[aks];//.front();
                
                four.push_back(temp.first);
                
                
                vector<string> ing = pzzIgdList[temp.first];
                                      
                set<string> common;
                for(int i = 0 ; i < temp.second ; i++)
                {
                      if (common.find(ing[i]) == common.end()) 
                      {
                         sc4++;
                         common.insert(ing[i]);
                      }
                }
                M--;
                a--;
                tm4++;
                aks++;
            }
            
            int b = T3*3;
            if(M < b && M % 3 > 0)
            {
                b = b - 3 ;
            }
            while(b>0 && M>0)
            {
                pair<int,int> temp;
                temp = pzzIgdCount[aks];//.front();
               
                three.push_back(temp.first);
                vector<string> ing = pzzIgdList[temp.first];
                                      
                set<string> common;
                for(int i = 0 ; i < temp.second ; i++)
                {
                      if (common.find(ing[i]) == common.end()) 
                      {
                         sc3++;
                         common.insert(ing[i]);
                      }
                }
                
                M--;
                b--;
                tm3++;
                aks++;
                
            }
           
            int c = T2*2 ;
            if(  M % 2 > 0)
            {
                c = c - 2 ;
            }
            
            while(c > 0 && M > 0)
            {
                pair<int,int> temp;
                temp = pzzIgdCount[aks];//.front();
                //pzzIgdCount.erase(pzzIgdCoun.begin());//.pop_front();
                two.push_back(temp.first);
                vector<string> ing = pzzIgdList[temp.first];
                          
                set<string> common;
                for(int i = 0 ; i < temp.second ; i++)
                {
                      if (common.find(ing[i]) == common.end()) 
                      {
                         sc2++;
                         common.insert(ing[i]);
                      }
                }
                M--;
                c--;
                tm2++;
                aks++;
            }

    int d = (tm4/4) + (tm3/3) + (tm2/2) ;
    cout<<d;
    
    for(int i = 0 ; i < two.size() ; i++)
    {
        
        if(i % 2 == 0 )
        {
            cout<<endl ;
            cout<<"2"<<" " ;
        }
        cout<<two[i]<<" " ;
      }
   
    
    for(int i = 0 ; i < three.size() ; i++)
    {
        if(i % 3 == 0 )
        {
            cout<<endl ;
            cout<<"3"<<" " ;
        }
        cout<<three[i]<<" " ;
       
    }
   
    
     for(int i = 0 ; i < four.size() ; i++)
    {
        if(i % 4 == 0 )
        {
            cout<<endl ;
            cout<<"4"<<" " ;
        }
        cout<<four[i]<<" " ;
        
    }
    

    // Optimize solution

}

int main(){
    
    freopen("e.in", "r", stdin);
    freopen("e.txt", "w", stdout);
    solve();
    return 0;
}