#include <iostream>
#include<vector>
#include<fstream>

using namespace std;
class Graph{
    private:
        int sodinh;
        int socanh;
        vector<int> *danhsachke;
    public:
        Graph(int V){
            sodinh = V;
            socanh = 0;
            danhsachke = new vector<int> [sodinh];
        }
        Graph (istream &in){
            int v, w;
            in>>sodinh;
            in>>socanh;
            for (int i=0; i < socanh; i++){
                in>>v>>w;
                danhsachke[v].push_back(w);
                danhsachke[w].push_back(v);
            }
        
        }
        void add(int v, int w){
            socanh++;
            danhsachke[v].push_back(w);
            danhsachke[w].push_back(v);
        }

        vector<int> getAdj(int v){
            return danhsachke[v];
        }
        int getDinh(){
            return sodinh;
        }
        int getCanh(){
            return socanh;
        }

        int getSize(int v){
            vector<int> kev = getAdj(v);
            return kev.size();
            }

};

// void pruferCodeCompression(int n, int sobac[],vector<int> danhSachKe[], int pruferCode[]) {    

//     int nhan = 1; while(sobac[nhan] != 1) nhan ++;  
//     int x = nhan;    

//     for (int i = 0; i <= n - 2; i++) {
//         sobac[x]--;                              
//         int viTri = 0;   
//         viTri = danhSachKe[x].front();
//         pruferCode[i] = viTri;                    
//         int index;
//         for (int j = 0; j < danhSachKe[viTri].size(); j++) {
//             if (danhSachKe[viTri][j] == x) {
//                 index = j;                            
//                 break;                                
//             }                                           
//         }

//         danhSachKe[viTri].erase(danhSachKe[viTri].begin()+index);       
//         sobac[pruferCode[i]]--;                                                 

//         int nhan = 1; 
//         while(sobac[nhan] != 1) nhan++;    
//         x = nhan;                                   

//     }
// }

int main() {

    int n = 10;                    

    Graph G(n-1);
    G.add(0,2);
    G.add(0,3);
    G.add(2,4);
    G.add(2,6);
    G.add(2,9);
    G.add(6,1);
    G.add(6,5);
    G.add(9,7);
    G.add(9,8);

    // vector<int> *danhSachKe = new vector<int> [n];                    
    // for (int i = 0; i < n; i++) {                  
    //     danhSachKe[i] = G.getAdj(i);
    // }

    // int sobac[n];                                     
    
    // for (int i = 0; i < n; i++) {
    //     sobac[i] = G.getSize(i);
    // }

    // int pruFercode[n - 2];

    // pruferCodeCompression(n, sobac, danhSachKe, pruFercode);

    // for (int i = 0; i < n - 2; i++) {
    //     cout << pruFercode[i] << " ";
    // }
    
    return 0;
}