/*
csp 201503-2	�������� 
��������
��������n����������ͳ�Ƴ�ÿ���������ֵĴ����������ִ����Ӷൽ�ٵ�˳�������
�����ʽ
��������ĵ�һ�а���һ������n����ʾ�������ֵĸ�����
�����ڶ��а���n�����������ڵ�����֮����һ���ո�ָ�����ʾ��������������
�����ʽ
������У�ÿ�а��������������ֱ��ʾһ�������������������ֵĴ�����
�����ִ����ݼ���˳���������������������ֵĴ���һ���࣬�������ֵ��С�ģ�Ȼ�����ֵ�ϴ�ġ�
��������
12
5 2 3 3 1 3 4 2 5 2 3 5
�������
3 4
2 3
5 3
1 1
4 1
*/
#include<iostream>

using namespace std;

typedef struct {
	int key;
	int value;
}Map;

int n;

void Set(Map *map, int key) {
	int i = key%n;
	while (1) {
		if (map[i].key == -1 || map[i].key == key) {
			map[i].key = key;
			map[i].value++;
			return;
		}
		i++;
		if (i == n) i = 0;
	}
}

int main() {
	scanf("%d", &n);
	int num[n];
	for (int i=0; i<n; i++) {
		scanf("%d", &num[i]);
	}
	
	Map map[n];
	for (int i=0; i<n; i++) {
		map[i].key = -1;
		map[i].value = 0;
	}
	
	for (int i=0; i<n; i++) {
		Set(map, num[i]);
	}	
	
	for (int i=0; i<n; i++) {
		if (map[i].key == -1) continue;
		Map max = map[i];
		int maxPos = i;
		for (int j=i; j<n; j++) {
			if (map[j].key == -1) continue;
			if ((map[j].value > max.value) 
				|| (map[j].value == max.value && map[j].key < map[i].key)) {
				max = map[j];
				maxPos = j;
			}
		}
		map[maxPos] = map[i];
		map[i] = max;
	}
	
	for (int i=0; i<n; i++) {
		if (map[i].key != -1) cout<<map[i].key<<" "<<map[i].value<<endl;
	}
	
	return 0;
}


