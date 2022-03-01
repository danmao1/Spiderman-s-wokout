#include <iostream>
#include <string.h>
#include <stdio.h>


using namespace std;
#define MAX 9999
int opt[41][1001];
int level[41][1001];
int heights[41];

void print_sol(int i,int height)
{
        
        if(i==0){
                return;
        }
        print_sol(i-1,level[i][height]);
        

        if(height>level[i][height]){
                printf("U");
                
        }
        else{
                printf("D");
                
        }
}
int main()
{
        int n;
        cin >> n;
        while(n!=0)
        {
                int m;
                
                cin >> m;
                int max_building=0;
                for(int i=1;i<=m;i++)
                {
                    cin >> heights[i];
                    max_building+=heights[i];
                }
                max_building=(max_building/2)+1;
                for(int i=0;i<=m;i++)
                        for(int j=0;j<=max_building;j++)
                                opt[i][j]=MAX;
                opt[0][0]=0;
                
                for(int i=1;i<=m;i++)
                {
                        for(int j=0;j<=max_building;j++)
                        {       
                                
                                if(j+heights[i]<=max_building && opt[i-1][j+heights[i]]!=MAX)
                                {
                                        if(opt[i][j]>max(opt[i-1][j+heights[i]],j))
                                        {
                                                opt[i][j]=max(opt[i-1][j+heights[i]],j);
                                                level[i][j]=j+heights[i];
                                        }
                                }

                                if(j-heights[i]>=0 && opt[i-1][j-heights[i]]!=MAX)
                                {
                                        if(opt[i][j]>max(opt[i-1][j-heights[i]],j))
                                        {
                                            opt[i][j]=max(opt[i-1][j-heights[i]],j);
                                            level[i][j]=j-heights[i];
                                        }                                                                                                                                                                                                              
                                }
                                
                        }
                }
                
                if(opt[m][0]==MAX){
                        cout << "IMPOSSIBLE\n";
                }
                else
                {
                        print_sol(m,0);
                        cout << "\n";
                }
                n--;
                
        }
        return 0;
}
