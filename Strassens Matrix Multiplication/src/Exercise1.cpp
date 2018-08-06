#include <iostream>
#include "simple_matrix.hpp"
using namespace std;

template<class T>
SMatrix<T> add(SMatrix<T> A, SMatrix<T> B){
    SMatrix<T> C(A.size());
    for(int i=0; i<A.size();++i){
        for(int j=0; j<A.size();++j){
            C(i,j) = A(i,j) + B(i,j);
        }
    }

    return C;
}

template<class T>
SMatrix<T> sub(SMatrix<T> A, SMatrix<T> B){
    SMatrix<T> C(A.size());
    for(int i=0; i<A.size();++i){
        for(int j=0; j<A.size();++j){
            C(i,j) = A(i,j) - B(i,j);
        }
    }

    return C;
}


template<class T>
SMatrix<T> strassensAlgo(SMatrix<T> A, SMatrix<T> B){

    SMatrix<T> C(A.size());
    if(A.size()==1){
        C(0,0) = A(0,0)* B(0,0);
    }
    else{
        const int H = A.size()/2;

        //matrices to divide the problem statement in parts.
//        SMatrix<T> A11[H][H],A12[H][H],A21[H][H],A22[H][H],
//                   B11[H][H],B12[H][H],B21[H][H],B22[H][H],
//                   C11[H][H],C12[H][H],C21[H][H],C22[H][H];
        SMatrix<T> A11(H),A12(H),A21(H),A22(H),
                   B11(H),B12(H),B21(H),B22(H),
                   C11(H),C12(H),C21(H),C22(H);

        SMatrix<T> S1(H),S2(H),S3(H),S4(H),S5(H),S6(H),S7(H),S8(H),S9(H),S10(H),
                   P1(H),P2(H),P3(H),P4(H),P5(H),P6(H),P7(H);

//        for(int i1 =0;i1<2;i1++){
//            for(int j1 =0;j1<2;j1++){
                for(int i =0;i<H;i++){
                    for(int j =0;j<H;j++){
                        A11(i,j) = A(i,j);
                        B11(i,j) = A(i,j);

                        A12(i,j) = A(i,H+j);
                        B12(i,j) = B(i,H+j);

                        A21(i,j) = A(H+i,j);
                        B21(i,j) = B(H+i,j);

                        A22(i,j) = A(H+i,H+j);
                        B22(i,j) = B(H+i,H+j);

                    }
                }
//            }
//        }
            S1  = sub(B12 , B22);
            S2  = add(A11 , A12);
            S3  = add(A21 , A22);
            S4  = sub(B21 , B11);
            S5  = add(A11 , A22);
            S6  = add(B11 , B22);
            S7  = sub(A12 , A22);
            S8  = add(B21 , B22);
            S9  = sub(A11 , A21);
            S10 = sub(B11 , B12);

            P1  = strassensAlgo(A11, S1);
            P2  = strassensAlgo(S2, B22);
            P3  = strassensAlgo(S3, B11);
            P4  = strassensAlgo(A22, S4);
            P5  = strassensAlgo(S5, S6);
            P6  = strassensAlgo(S7, S8);
            P7  = strassensAlgo(S9, S10);

            C11 = P4 + P5 + P6 - P2
            C12 = P1 + P2
            C21 = P3 + P4
            C22 = P1 + P5 - P3 - P7

            for (i = 0; i < H ; i++) {
            for (j = 0 ; j < H ; j++) {
                C(i,j) = c11(i,j);
                C(i,j+H) = c12(i,j);
                C(i+H,j) = c21(i,j);
                C(i+H,j+H) = c22(i,j);
            }
        }

        return C;

}


int main()
{
    ifstream in(argv[1]);

    if(!in){
        cout<<"Cannot open  input file;"<<endl;
        return -1;
    }

    ofstream out(argv[2]);

    if(!out){
        cout<<"Cannot open  output file;"<<endl;
        return -1;
    }
int datasets;
in>>datasets;



for(int i=0;i<datasets;i++)
{
    int N;
	in>>N;


    SMatrix<float> A(N), B(N), C(N);


	for(int j=0;j<N;j++)
	{
        for(int k=0;k<N;k++)
        {
		in>>A(j,k);
	}
    }
        for(int j=0;j<N;j++)
	   {
        for(int k=0;k<N;k++)
        {
		in>>B(j,k);
	    }
        }

        C = strassensAlgo(A, B);


        for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            out<<C(i,j)<<" ";
        }}

        out<<endl;
}

    return 0;
}
