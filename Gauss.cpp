#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
const int MAXN = 50;
int a[MAXN][MAXN];//�������
int x[MAXN];//�⼯
bool free_x[MAXN];//����Ƿ��ǲ�ȷ���ı�Ԫ
int gcd(int a, int b){
	if(b == 0) return a; else return gcd(b, a % b);
} 
inline int lcm(int a, int b){
	return a / gcd(a, b) * b;//�ȳ���˷���� 
}

//-2��ʾ�и������⣬����������
//-1��ʾ�޽⣬0��ʾΨһ�⣬����0��ʾ����⣬���������ɱ�Ԫ����
//��equ�����̣�var����Ԫ �����������Ϊequ�� �ֱ�Ϊ0 ��equ-1�� ����var+1��

int Gauss(int equ, int var){
	int i, j, k;
	int max_r;//��ǰ���о���ֵ������
	int col;//��ǰ�������
	int ta, tb;
	int LCM;
	int temp;
	int free_x_num;
	int free_index;
	
	for(int i = 0; i <= var; i++){
		x[i] = 0;
		free_x[i] = true;
	} 
	
	//ת��Ϊ������
	col = 0;//��ǰ�������
	for(k = 0; k < equ && col < var; k++, col++){//ö�ٵ�ǰ�������
	//�ҵ���col��Ԫ�ؾ���ֵ�����������k�н�����Ϊ���ڳ���ʱ��С��
		max_r = k;
		for(i = k + 1; i < equ; i++){
			if(abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
		} 
		if(max_r != k)
			for(j = k; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
		if(a[k][col] == 0){
		//˵����col�е�k������ȫ��0�ˣ�����ǰ�е���һ�� 
			k--;
			continue;
		}
		for(i = k + 1; i < equ; i++){//ö��Ҫɾȥ����
			if(a[i][col] != 0){
				LCM = lcm(abs(a[i][col]), abs(a[k][col]));
				ta = LCM / abs(a[i][col]);
				tb = LCM / abs(a[k][col]);
				if(a[i][col] * a[k][col] < 0) tb = - tb;//��ŵ���������
				for(j = col; j < var + 1; j++){
					a[i][j] = a[i][j] * ta - a[k][j] * tb;
				} 
			} 
			
		}
	
	} 
	
	//�޽��������������������д��ڣ�0,0����������a������������a��= 0
	for(i = k; i < equ; i++){
		if(a[i][col] != 0) return -1;//�����������˵�����Ҫ�ж���Щ�����ɱ�Ԫ����ô�����б任�еĽ����ͻ�Ӱ�죬��Ҫ��¼����
		
	} 
	//�������������var*(var + 1)���������г���(0, 0, ..., 0)�������У���˵��û���γ��ϸ����������.
	 // �ҳ��ֵ�������Ϊ���ɱ�Ԫ�ĸ���.
	if(k < var){
		return var - k;
	} 
	
	// 3. Ψһ������: ��var * (var + 1)�����������γ��ϸ����������.
        // �����Xn-1, Xn-2 ... X0.
    for(i = var - 1; i >= 0; i--){
    	temp = a[i][var];
    	for(j = i + 1; j < var; j++){
    		if(a[i][j] != 0) temp -= a[i][j] * x[j];
		}
		if(temp % a[i][j] != 0) return -2;
		x[i] = temp / a[i][i];
	}
	return 0;
} 

int main(void)
{
	int i, j;
	int equ,var;
	while(scanf("%d %d",&equ, &var) != EOF){
		memset(a, 0, sizeof(a));
		for(i = 0; i < equ; i++){
			for(j = 0; j < var + 1; j++){
				scanf("%d",&a[i][j]);
			}
		}
		int free_num = Gauss(equ,var);
	}
}
