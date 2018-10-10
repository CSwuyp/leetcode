/*这程序主要特点是事先并不知道学生人数也不知道学生有多少科目的成绩最后输出结果是学生的平均成绩排序从大到小*/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	string name;
	int ave;
}Stu;
vector<Stu> vec;
int cmp(const Stu& lhs, const Stu& rhs)
{
	return lhs.ave > rhs.ave;
}
int main() {
	string line;
	stringstream ss;
	while (getline(cin, line) && line != "") 
	{
		Stu s;
		int cnt = 0;
		double sum = 0.0;
		double score;
		ss.clear();
		ss << line;
		//cout << ss << endl;
		ss >> s.name;
		//cout << s.name << endl;
		while (ss >> score) 
		{
			sum += score;
			cnt++;
		}
		s.ave = (int)(sum / (double)cnt + 0.5);//这里+0.5的意思是如果4舍5入
		//cout << s.ave << endl;
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end(),cmp);
	for (int i = 0; i < vec.size(); ++i) 
	{
		cout << vec[i].name << " " << vec[i].ave << endl;
	}
	return 0;
}
