/*
csp 2018��12 ��3�� CIDR�ϲ�
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct IpPref {
	unsigned int ip;
	int pref[4];
	int len;
};

int n;

IpPref handle(char *str, int strLen) {
	IpPref ret;		// ����ֵ 
	char s[4][4];	// ipǰ׺��ַ���Ĳ��� 
	
	int count = 0, pre = 0;	// ip��ַ�ĵڼ����֣���һ��'.'��'/'����һ��λ�� 
	for (int i=0; i<strLen; i++) {
		if (str[i] == '.' || str[i] == '/') {
			int k=0;
			for (int j=pre; j<i; j++, k++) {
				s[count][k] = str[j];
			}
			s[count][k] = '\0';
			count++;
			pre = i+1;
			// printf("%s\n", s[count-1]);
		}
	}
	
	// ��ipǰ׺�ĳ���
	ret.len = 0;	// ipǰ׺����
	if (pre != 0 && str[pre-1] == '/') {
		int i;
		for (i=pre; i<strLen; i++) {
			ret.len = ret.len*10 + (str[i] - '0'); 
		}
		str[i] = '\0';
	}
	else {
		ret.len = (count+1) * 8;
	}
	
	// ��IP��ַ��ʣ�ಿ�� 
	if (count == 0 || str[pre-1] != '/') {
		int k=0;
		for (int i=pre; i<strLen; k++,i++) {
			s[count][k] = str[i];
		}
		s[count][k] = '\0';
		count++;
	}
	while (count < 4) {
		s[count][0] = '0';
		s[count][1] = '\0';
		count++;
	}
	
	// ��ip��ַ��ʮ������ 
	int num;
	ret.ip = 0;
	for (int i=0; i<4; i++) {
		ret.pref[i] = 0;
		for (int j=0; j<strlen(s[i]); j++) {
			ret.pref[i] = ret.pref[i]*10 + s[i][j] - '0';
		}
		ret.ip = ret.ip * 256 + ret.pref[i];
		//printf("%d  %d\n", ret.ip, ret.pref[i]);
	}
	
	return ret;
}

bool cmp(IpPref a, IpPref b) {
	if (a.ip < b.ip) {
		return true;
	}
	else if (a.ip == b.ip && a.len < b.len) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	n = 0;
	scanf("%d", &n);
	
	// ��ʼ���������ַ��� 
	IpPref *prefList = (IpPref*)malloc(sizeof(IpPref) * n);
	char str[100];
	for (int i=0; i<n; i++) {
		scanf("%s", str);
		prefList[i] = handle(str, strlen(str));
	}
	
	// ���� 
	sort(prefList, prefList+n, cmp);
	
	// ��С����ϲ�
	IpPref pre = prefList[0];
	for (int i=1; i<n; i++) {
		// ��������λ���㣬�����ͬ�Ĳ����ڸ�pre.lenλ֮��(����֮��Ϊ0)����ô����pre���Ӽ����� 
		if ((pre.ip^prefList[i].ip)>>(32-pre.len) == 0) {
			prefList[i].len = -1;
		}
		else {
			pre = prefList[i];
		}
	}
	
	// ͬ���ϲ�
//	for (int i=0, j=1; j<n, i<n;) {
//		if (prefList[j].len == -1) {
//			j++;
//			continue;
//		}
//		if (prefList[i].len == -1) {
//			i++;
//			continue;
//		}
//		if ((prefList[i].ip^prefList[j].ip)>>(32-prefList[i].ip) == 1) {
//			prefList[j].len = -1;
//			prefList[i].len--;
//			if (i >= 1) {
//				j = i;
//				i--;
//				continue;
//			}
//		}
//		i = j;
//		j++;
//	}

	// ��� 
	for (int i=0; i<n; i++) {
		if (prefList[i].len == -1) continue; 
		int j=0;
		for (; j<3; j++) {
			printf("%d.", prefList[i].pref[j]);
		}
		printf("%d/%d\n", prefList[i].pref[j], prefList[i].len);
	}
}
