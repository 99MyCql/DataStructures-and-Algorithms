/*
@Title: ��Ϣ���ݽӿ�
@Example:
3 2
R1 S1
S0 R0
R1 S1
R0 S0
R1 R1 R1 R1 S1 S1 S1 S1
S0 S0 S0 S0 R0 R0 R0 R0

2 3
R1 S1
R2 S0 R0 S2
S1 R1
R1
R2 S0 R0
S1 R1
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<list>

using namespace std;

typedef struct PID {
	int obj;
	char type; // 0��ʾR��1��ʾS 
};

int main() {
	int T=0, n=0;
	scanf("%d %d", &T, &n);
	cin.ignore();
	for (int i=0; i<T; i++) {
		list<PID> pidList[n];
		for (int j=0; j<n; j++) {
			char str[100];
			cin.getline(str, 100);
			
			PID temp;
			for (int k=0; k<strlen(str); k+=3) {
				temp.obj = str[k+1] - '0';
				if (str[k] == 'R') temp.type = 0;
				else temp.type = 1;
				pidList[j].push_back(temp);
			}
		}
		
		// ��� 
//		for (int j=0; j<n; j++) {
//			list<PID>::iterator it = pidList[j].begin();
//			while (it != pidList[j].end()) {
//				printf("%d--%d  ", it->type, it->obj);
//				it++;
//			}
//			printf("\n");
//		}
		
		// ��ִ�� 
		queue<int> q;
		for (int i=0; i<n; i++) q.push(i);
		
		// �ȴ����ܵĽ���
		int waitR[n];
		for (int i=0; i<n; i++) waitR[i] = -1;
		
		// �ȴ����͵Ľ���
		int waitS[n];
		for (int i=0; i<n; i++) waitS[i] = -1;
		
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			
			if (pidList[cur].empty()) continue;
			
			list<PID>::iterator it = pidList[cur].begin();
			// 1��ʾ���� 
			if (it->type) {
				if (waitR[it->obj] == cur) {
					pidList[it->obj].erase(pidList[it->obj].begin());
					waitR[it->obj] = -1;
					q.push(cur);
					q.push(it->obj);
					pidList[cur].erase(it);
				}
				else {
					waitS[cur] = it->obj;
				}
			}
			// 0��ʾ���� 
			else {
				if (waitS[it->obj] == cur) {
					pidList[it->obj].erase(pidList[it->obj].begin());
					waitS[it->obj] = -1;
					q.push(cur);
					q.push(it->obj);
					pidList[cur].erase(it);
				}
				else {
					waitR[cur] = it->obj;
				}
			}
		}
		
		// ����Ƿ���ʣ�µ�ָ��о������� 
		bool flag = true;
		for (int j=0; j<n; j++) {
			if (!pidList[j].empty()) {
				printf("1\n");
				flag = false;
				break;
			}
		}
		if (flag) printf("0\n");
	}
}
