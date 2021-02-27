/*
11
H2+O2=H2O
2H2+O2=2H2O
H2+Cl2=2NaCl
H2+Cl2=2HCl
CH4+2O2=CO2+2H2O
CaCl2+2AgNO3=Ca(NO3)2+2AgCl
3Ba(OH)2+2H3PO4=6H2O+Ba3(PO4)2
3Ba(OH)2+2H3PO4=Ba3(PO4)2+6H2O
4Zn+10HNO3=4Zn(NO3)2+NH4NO3+3H2O
4Au+8NaCN+2H2O+O2=4Na(Au(CN)2)+4NaOH
Cu+As=Cs+Au

1
2NO3=(NO3)2
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

// #define debug

typedef long long ll;

map<string, int> formula(char *str, int len, int &p);

map<string, int> term(char *str, int len, int &pos) {
	#ifdef debug
	printf("term():%c---%c, %d:%c\n", str[0], str[len-1], pos, str[pos]);
	#endif
	map<string, int> ret_map;
	// ���ƥ�䵽�����ţ���˵���ǲ���ʽ (formula)
	if (str[pos] == '(') {
		#ifdef debug
		cout << "find (\n";
		#endif
		pos++;
		int i;
		// �ҵ���֮ƥ���������
		for (i = len-1; i >= 0; i--) {
			if (str[i] == ')') {
				#ifdef debug
				cout << "find )\n";
				#endif
				int p = 0;
				ret_map = formula(str+pos, i-pos, p); // ʹ��formula����������Ӧ����
				break;
			}
		}
		pos = i+1;
	}
	// ��֮��˵����Ԫ����
	else {
		if (str[pos] >= 'A' && str[pos] <= 'Z') {
			pos++;
			if (str[pos] >= 'a' && str[pos] <= 'z') {
				pos++;
				string s(str+pos-2, str+pos);
				ret_map[s] = 1;
				#ifdef debug
				cout << "term:" << s <<endl;
				#endif
			}
			else {
				string s(str+pos-1, str+pos);
				ret_map[s] = 1;
				#ifdef debug
				cout << "term:" << s <<endl;
				#endif
			}
		}
	}
	return ret_map;
}

// ����ϵ��
ll coef(char *str, int len, int &pos) {
	#ifdef debug
	printf("coef():%c---%c, %d:%c\n", str[0], str[len-1], pos, str[pos]);
	#endif
	ll sum = 0;
	for (; pos < len && str[pos] >= '0' && str[pos] <= '9'; pos++) {
		sum = sum*10 + (str[pos]-'0');
	}
	if (sum == 0) sum = 1;
	#ifdef debug
	printf("coef:%d\n", sum);
	#endif
	return sum;
}


map<string, int> formula(char *str, int len, int &pos) {
	#ifdef debug
	printf("formula():%c---%c, %d:%c\n", str[0], str[len-1], pos, str[pos]);
	#endif
	map<string, int> sum_map;
	// formula����������ʽ��<formula> <term> <coef> || <term> <coef>
	// ���Խ���������ʽ�ϲ�Ϊ <term> <coef> ...... <term> <coef> ��ת���� <term> <coef> ������ѭ��
	// ���ڲ����ڷ��ս�����������֣�������Ҫpos��־����¼����Ľ���
	while (pos<len) {
		map<string, int> term_map = term(str, len, pos);
		ll c = coef(str, len, pos);
		for (map<string, int>::iterator it=term_map.begin(); it!=term_map.end(); it++) {
			string e = it->first;
			int count = c * it->second;
			if (sum_map.count(e)) sum_map[e] += count;
			else sum_map[e] = count;
		}
	}
	return sum_map;
}

map<string, int> expr(char *str, int len) {
	#ifdef debug
	printf("expr():%c---%c\n", str[0], str[len-1]);
	#endif

	// ����ǲ���ʽ��<expr> + <coef><formula>
	for (int i=len-1; i>=0; i--) {
		// �ҵ����һ�����ս��+
		if (str[i] == '+') {
			// ����<expr>
			map<string, int> exp_map = expr(str, i);
			// ����<coef>
			int p = 0;
			ll c = coef(str+i+1, len-i-1, p);
			// ����<formula>
			int pos = 0;
			map<string, int> f_map = formula(str+i+1+p, len-i-1-p, pos);

			// �ϲ�expr��coef*formula��Ԫ��map
			for (map<string, int>::iterator it=f_map.begin(); it != f_map.end(); it++) {
				string e = it->first;
				int count = c * it->second;
				if (exp_map.count(e)) exp_map[e] += count;
				else exp_map[e] = count;
			}

			return exp_map;
		}
	}

	// ����ǲ���ʽ��<coef><formula>
	int p=0;
	ll c = coef(str, len, p);
	int pos = 0;
	map<string, int> f_map = formula(str+p, len-p, pos);
	// ����coef*formula��Ԫ��map
	for (map<string, int>::iterator it=f_map.begin(); it!=f_map.end(); it++) {
		it->second *= c;
	}
	return f_map;
}

bool equation(char *str, int len) {
	#ifdef debug
	printf("equation():%c---%c\n", str[0], str[len-1]);
	#endif
	for (int i=0; i<len; i++) {
		// ���ݷ��ս�� = ��������expr
		if (str[i] == '=') {
			// ������expr�и�Ԫ�ص�������ʹ�� map<Ԫ������Ԫ�ظ���> ����
			map<string, int> lmap = expr(str, i);
			#ifdef debug
			cout << "lmap:\n";
			for (map<string, int>::iterator it=lmap.begin(); it!=lmap.end(); it++) {
				cout << it->first << ", " << it->second << endl;
			}
			#endif

			// ������expr�и�Ԫ�ص�����
			map<string, int> rmap = expr(str+i+1, len-i-1);
			#ifdef debug
			cout << "rmap:\n";
			for (map<string, int>::iterator it=rmap.begin(); it!=rmap.end(); it++) {
				cout << it->first << ", " << it->second << endl;
			}
			#endif

			// �������expr�Ƿ���ƽ
			if (lmap.size() != rmap.size()) return false;
			for (map<string, int>::iterator it=lmap.begin(); it!=lmap.end(); it++) {
				if (!rmap.count(it->first)) return false;
				else if (lmap[it->first] != rmap[it->first]) return false;
			}
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		char str[1000];
		char *p = str;
		scanf("%s", str);
		int len = strlen(str);
		if (equation(p, len)) {
			printf("Y\n");
		}
		else {
			printf("N\n");
		}
	}
}
