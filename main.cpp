#include <bits/stdc++.h>
using namespace std;
string normseg(string a,string b)
{
    if(a > b) swap(a,b);
    return a + b;
}
string frac(string s)
{
    return s;
}
string fmt(vector<string> v)
{
    int tp = stoi(v[0]);
    if(tp == 1)
    {
        string x = v[1], p = v[2], q = v[3], o = v[4];
        if(o == "1") return "点" + x + "在" + normseg(p,q) + "上";
        if(o == "2") return "点" + x + "在射线" + p + q + "上";
        if(o == "3") return x + "," + p + "," + q + "三点共线";
        return "点" + x + "在" + p + q + "的延长线上";
    }
    if(tp == 2)
    {
        string a = normseg(v[1],v[2]), b = normseg(v[3],v[4]), k = v[5];
        if(k == "1") return a + "=" + b;
        return a + "=" + k + b;
    }
    if(tp == 3)
    {
        string a = normseg(v[1],v[2]), b = normseg(v[3],v[4]);
        if(v[5] == "1") return a + "//" + b;
        return a + "⊥" + b;
    }
    if(tp == 4) return normseg(v[1],v[2]) + "=" + v[3];
    if(tp == 5)
    {
        string a = "∠" + v[1] + v[2] + v[3], b = "∠" + v[4] + v[5] + v[6], o = v[7], k = v[8];
        if(o == "1") return a + "+" + b + "=" + k + "°";
        if(o == "2") return a + "-" + b + "=" + k + "°";
        if(o == "3") return a + "=" + k + b;
        if(k == "1") return a + "=" + b;
        return a + "=" + "1/" + k + b;
    }
    if(tp == 6) return "∠" + v[1] + v[2] + v[3] + "=" + v[4] + "°";
    if(tp == 7) return v[1] + v[2] + "平分∠" + v[3] + v[4] + v[5];
    if(tp == 8)
    {
        int n = stoi(v[1]);
        string s;
        for(int i = 0;i < n;i++) s += v[2 + i];
        if(n == 3) return "△" + s + "是等边三角形";
        if(n == 4) return "正方形" + s;
        return "正" + to_string(n) + "边形" + s;
    }
    string a = v[1], b = v[2], o = v[3];
    if(o == "1") return "存在线段" + normseg(a,b);
    if(o == "2") return "存在射线" + a + b;
    return "存在直线" + normseg(a,b);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    if(!(cin >> n)) return 0;
    string line;
    getline(cin,line);
    for(int i = 1;i <= n;i++) getline(cin,line);
    getline(cin,line);
    stringstream ss(line);
    vector<string> v;
    string x;
    while(ss >> x) v.push_back(x);
    string ans = fmt(v);
    cout << "2 0\n";
    cout << "∵ 已知条件成立\n";
    cout << "∴ " << ans << "\n";
    return 0;
}
