/*
csp 201712-4	�г�·��
[��������]
����С����С����ȥ����棬С�����𿪳���С����������
����С�������ܵĵ�·��Ϊ�����С��������ȽϺ��ߣ�ÿ��1����С��������1��ƣ�Ͷȡ�
	С�������ߣ����������С����С����ƣ��ֵ��������ӣ�������s����С��������s2��ƣ�Ͷȡ�
�������磺��5��·�ڣ�1��·�ڵ�2��·��ΪС����2��·�ڵ�3��·��ΪС����3��·�ڵ�4��·��Ϊ�����
	4��·�ڵ�5��·��ΪС��������·��֮��ľ��붼��2������С����1��·�ڵ�5��·�ڣ�
	����ƣ��ֵΪ(2+2)2+2+22=16+2+4=22��
	����С���õ��˵�ͼ����������滮һ��������·�ߣ�ʹ�ð����·�߿���С����ƣ�Ͷ���С��
[����Ҫ��]
�����ʽ��
��������ĵ�һ�а�����������n, m���ֱ��ʾ·�ڵ������͵�·��������·����1��n��ţ�
	С����Ҫ������1��·�ڵ�n��·�ڡ�
������m��������·��ÿ�а����ĸ�����t, a, b, c����ʾһ������Ϊt������a��b����·�ڣ�
����Ϊc�����˫���·��
����tΪ0��ʾ�����tΪ1��ʾС������֤1��·�ں�n��·������ͨ�ġ�
�����ʽ
���һ����������ʾ����·����С����ƣ�Ͷȡ�
��������
6 7
1 1 2 3
1 2 3 2
0 1 3 30
0 3 4 20
0 4 5 30
1 3 5 6
1 5 6 1
�������
76
����˵��
������1��С����2������С����3��ƣ�Ͷ�Ϊ5^2=25��Ȼ���3�ߴ������4����5��ƣ�Ͷ�Ϊ20+30=50��
����5��С����6��ƣ�Ͷ�Ϊ1���ܹ�Ϊ76��
�γ����Ҫ��
��1��Ҫ����ı��ļ������룻
��2�������ʵ������ݽṹ�洢�����������еĵ�·���γɵ�ͼ�ṹ��
��3����д�������ŵ��㷨�������������С����ɵ�ƣ��ֵ��ָ������
����ʾ�����ڵϽ�˹�����㷨���иĽ�������ɱ��⣩��
��4�����ϸ���ĿҪ�����������⣬��Ҫ���������·�ߵ�·�����Լ��ӳ����㵽���������Сƣ��ֵ��
*/
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>

using namespace std;

#define LL long long

typedef struct 
{
	char type;	// 1ΪС����0Ϊ��� 
	LL length;	// �ߵ�Ȩ�أ�0��ʾ������ 
}Arc;

typedef struct 
{
	LL pre;		// ���·������һ���� 
	LL length;		// ���õ�(�����±�Ϊ��Ӧ��ŵĵ�)����ʼ������·������ 
	bool final;		// �Ƿ�����С·���� 
}Djs;


LL n = 0, m = 0;	// ������ͱ߸��� 
Arc **graph;		// �ڽӾ��� 
Djs *dj = NULL;		// ���Ͻ�˹����ִ������ 
LL **flo = NULL;	// ��סÿ������֮�䶼ΪС·��ͨ· 
LL *order = NULL;	// order���鰴�յ㵽������·����С�������� 


// ��ʼ������ 
void Init()
{
	scanf("%d%d", &n, &m);
	
	// ��ʼ��ͼ�ͷ�������ͼ 
	graph = (Arc**)malloc(sizeof(Arc*) * (n+1));
	flo = (LL**)malloc(sizeof(LL*) * (n+1));
	for (LL i=0; i<=n; i++) 
	{
		graph[i] = (Arc*)malloc(sizeof(Arc) * (n+1));
		flo[i] = (LL*)malloc(sizeof(LL) * (n+1));
	}
	for (LL i=0; i<=n; i++) 
	{
		for (LL j=0; j<=n; j++) 
		{
			graph[i][j].type = 0;
			graph[i][j].length = 0;
			flo[i][j] = 0;
		}
	} 
	
	//��ʼ��order
	order = (LL*)malloc(sizeof(LL) * (n+1));
	for (LL i=1; i<=n; i++)
	{
		order[i] = 0;
	}
	
	// �������ݸ�ͼ��ֵ
	LL x = 0, y = 0, type = 0, length = 0;
	for (LL i=1; i<=m; i++) 
	{
		scanf("%d%d%d%d", &type, &x, &y, &length);
		graph[x][y].type = type;
		graph[x][y].length = length;
		graph[y][x] = graph[x][y];
		if (type)
		{
			flo[x][y] = length;
			flo[y][x] = length;
		}
	}
	
	// ��ʼ���Ͻ�˹�����㷨���ݽṹ����ֵ 
	dj = (Djs*)malloc(sizeof(Djs) * (n+1));
	for (LL i=1; i<=n; i++)
	{
		dj[i].final = false;
		dj[i].pre = 1;
		if (graph[1][i].type) 
		{
			dj[i].length = graph[1][i].length * graph[1][i].length;
		} 
		else 
		{
			dj[i].length = graph[1][i].length;
		}
	}
	dj[1].final = true;
	order[1] = 1;
	
	// ���flo
	for (LL k=1; k<=n; k++) 
	{
		for (LL i=1; i<=n; i++)
		{
			for (LL j=1; j<=n; j++)
			{
				if (i == j) continue;
				if ((flo[i][j] && flo[i][k] && flo[k][j] && flo[i][k]+flo[k][j]<flo[i][j])
					|| (!flo[i][j] && flo[i][k] && flo[k][j]))
				{
					flo[i][j] = flo[i][k]+flo[k][j];
				}
			}
		}
	}
}

// ��������
void Finish() 
{
	for (LL i=0; i<=n; i++) 
	{
		free(graph[i]);
	}
	free(graph);
	
	for (LL i=0; i<=n; i++) 
	{
		free(flo[i]);
	}
	free(flo);
	
	free(dj);
	
	free(order);
} 

// ������������ĳ�㵽��ʼ��ĳ��� 
LL getLength(LL cur, LL pre) 
{
	LL length = INT_MAX;
	//cout<<"====="<<pre<<"===="<<cur<<"===="<<(LL)graph[pre][cur].type<<"====="<<endl;
	 
	// �����ǰ�㵽��һ����֮����С�� 
	if (graph[pre][cur].type) 
	{
		LL sum = INT_MAX;
		// ����pre�������ǰ����Ϊ��·�� 
		for (LL i=1; i<=n; i++)
		{
			if (dj[i].final && graph[i][pre].length && !graph[i][pre].type)
			{
				sum = graph[pre][cur].length * graph[pre][cur].length +  graph[i][pre].length + dj[i].length;
				if (sum < length) length = sum;
			}
		}
		//cout<<"1---->"<<length<<endl;
		
		// ����������pre��Ϊ�յ㣬��ͨ·�϶�ΪС·��ʼ�㡣��flo�������¾�����pre�����һ���㡣���������յ�������·����С����ĵ� 
		for (LL i=1; i<=n; i++)
		{
			if (dj[order[i]].final && flo[order[i]][pre])
			{
				LL smallLen = graph[pre][cur].length + flo[order[i]][pre];
				sum = smallLen * smallLen + dj[order[i]].length;
				if (sum < length) length = sum;
				break;
			}
		}
		//cout<<"2---->"<<length<<endl;
	}
	// �����ǰ�㵽��һ����֮���Ǵ�� 
	else
	{
		length = graph[pre][cur].length + dj[pre].length;
	}
	
	//cout<<"======="<<length<<"======="<<endl;
	return length;
}

// ���ݵϽ�˹���������·�� 
void FindDjs() 
{
	// 2��n����n-1�Σ���Ϊ��ʼ���Ѿ�Ϊtrue 
	for (LL i=2; i<=n; i++) 
	{
		LL min = INT_MAX, minPos = i;
		for (LL j=1; j<=n; j++) 
		{
			if (dj[j].length && !dj[j].final && dj[j].length<min) 
			{
				min = dj[j].length;
				minPos = j;
			}
		}
		dj[minPos].final = true;
		order[i] = minPos;
		
		// ����ÿ��������·�� 
		for (LL j=1; j<=n; j++) 
		{
			// ��1��dj[j].finalΪfalse��˵������㻹δ�õ����·�� 
			// ��2��graph[minPos][j].length��Ϊ0����˵��jλ�ö��������µ�����
			//  ����������������������Ҫ�ж�j���Ƿ���Ҫ���� 
			if (!dj[j].final && graph[minPos][j].length) 
			{
				// ��ǰһ������newPosʱ����ȡposλ�õ����·��(�����) 
				LL newLength = getLength(j, minPos);
				// ���posλ�õ㻹δ�������·�� 
				if (!dj[j].length)
				{
					dj[j].length = newLength;
					dj[j].pre = minPos;
				}
				// ���posλ�õ������·�� 
				else
				{
					if (newLength < dj[j].length) 
					{
						dj[j].length = newLength;
						dj[j].pre = minPos;
					}
				}
			}
		}
	}
}

int main() {
	Init();
	FindDjs();
	printf("%d\n", dj[n].length);
	Finish();
}
