#include <vector>
#include <unordered_set>
#include <string>



class TwentyFourSolver {
public:
    std::vector<std::string> Solve24(std::vector<int>& nums) {
        
        double eps = 1e-6;
        std::vector<char> ops{'+', '/', '-', '*', '^'};
        std::vector<std::string> output;
        std::vector<std::string> desr;
        std::vector<double> dnums;
        for(auto const &num : nums) {
            dnums.push_back(num);
            desr.push_back(std::to_string(num));
        }
        std::unordered_set<std::string> set;
        get24s(dnums, desr, ops,eps, set);
        output.assign(set.begin(), set.end());
        return output;
    }
private:
    //recursion
    void get24s(std::vector<double>& nums, std::vector<std::string> &des, std::vector<char> &ops,  double eps, std::unordered_set<std::string>& output){
        if(nums.size() ==1) { if(abs(nums[0]-24)<eps)  output.insert(des[0]);  return;}

        for(int i=0; i < nums.size(); ++i){
            for(int j=0; j< nums.size(); ++j){
                if(i==j) continue;
                std::vector<double> t;
                std::vector<std::string> s;
                for(int k=0; k<nums.size(); ++k){
                    if(k!=i && k!=j) {
                        t.push_back(nums[k]);
                        s.push_back(des[k]);
                    }
                }
                for(auto op : ops){
                    if((op=='+'||op=='*')&& i>j) continue;
                    if(op=='/'&&nums[j]<eps) continue;
                    switch(op){
                        case '+':
                        t.push_back(nums[i]+nums[j]);
                        s.push_back("("+des[i] +"+"+ des[j]+")");
                        break;
                        case '*':
                        t.push_back(nums[i]*nums[j]);
                        s.push_back("("+des[i] +"*"+ des[j]+")");
                        break;
                        case '/':
                        t.push_back(nums[i]/nums[j]);
                        s.push_back("("+des[i] +"/"+ des[j]+")");
                        break;
                        case '-':
                        t.push_back(nums[i]-nums[j]);
                        s.push_back("("+des[i] +"-"+ des[j]+")");
                        break;
                        case '^':
                        t.push_back(pow(nums[i], nums[j]));
                        s.push_back("("+des[i] +"^"+ des[j]+")");
                    }
                    get24s(t, s, ops, eps, output);
                    t.pop_back();
                    s.pop_back();
                }
            }
        }
    }
};

