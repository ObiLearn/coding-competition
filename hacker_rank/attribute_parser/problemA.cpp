#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <regex>
#include <iomanip>

using namespace std;
using namespace std::literals::string_literals;

int level=3;

struct debug {
    int _level;

    debug(int i =1): _level(i) {}
    debug const& operator <<(string const& s) const{
        if(_level <= level) {
            std::cout << "#### " << s << std::endl;
        }
        return *this;
    };

    debug const& operator <<(int const& i) const {
        return operator<<(std::to_string(i));
    }
};

struct tag_container {
    tag_container* parent;
    string name;
    map<string,string> attr;
    map<string,tag_container> sub;
    int depth = 0;
};

std::ostream& operator<<(std::ostream& os, tag_container const& c) {
        std::string indent(8 * c.depth, ' ');
        os << indent <<  "name:" << c.name << " - ";
        for (auto const& p : c.attr) {
            os << p.first << ":" << p.second << " ";
        }
        os << "\n";
        for (auto const& s : c.sub) {
            os << s.second << std::endl;
        }
        os << indent << "name(end):" << c.name;
        return os;
}

vector<tag_container> vec;
tag_container* current = nullptr;
std::string const not_found = "Not Found!";

std::regex tag_re("^<(/)?(\\w+)(.*)>$");
int tag_re_close = 1;
int tag_re_name = 2;
int tag_re_attrs = 3;

std::regex attr_re(" (\\w+) = \"([^\"]*)\"");
int attr_re_key = 1;
int attr_re_value = 2;

void parse_tag(string const& s){

    std::smatch match_groups;
    std::regex_match(s, match_groups, tag_re);
    if (match_groups.empty()) {
        throw std::invalid_argument("tag does not match tag re");
    }

    bool close = !match_groups[tag_re_close].str().empty();
    std::string name = match_groups[tag_re_name].str();
    std::string attrs_string = match_groups[tag_re_attrs].str();

    std::map<std::string, std::string> attrs;
    while(std::regex_search(attrs_string, match_groups, attr_re)){
        std::string key = match_groups[attr_re_key].str();
        std::string value = match_groups[attr_re_value].str();
        attrs.emplace(key,value);
        attrs_string = match_groups.suffix();
    }

   if (!close) {
       if (current == nullptr) {
           vec.push_back({});
           current = &vec.back();
       } else {
           tag_container& sub = current->sub[name];
           sub.depth = current->depth + 1;
           sub.parent  = current;
           current = &sub;
       }
       current->name = name;
       current->attr = std::move(attrs);

   } else {
       if (current) {
            current = current->parent;
       }
   }

}

void show_all(std::vector<tag_container> vec) {
    for (auto const& c : vec) {
        std::cout << c << std::endl;
    }

}


std::regex query_re("([^~\\.]+)");

string parse_queries(string s) {
    std::vector<std::string> tags;
    std::smatch match_groups;

    while(std::regex_search(s, match_groups, query_re)){
        tags.push_back(match_groups[1]);
        s = match_groups.suffix();
    }

    if (tags.size() < 2) {
        throw std::invalid_argument("invald query");
    }

    std::string attr = tags.back();
    tags.pop_back();

    current = nullptr;
    for (auto& x : vec) {
        if (x.name == tags[0]) {
            current = &x;
            break;
        }
    }

    if (current) {
        for(auto it = tags.begin()+1; it != tags.end(); it++ ) {
            auto& n = current->sub[*it];
            if (n.name != *it) {
                return not_found;
            }
            current = &n;
        }

    } else {
        return not_found;
    }

    auto att = current->attr[attr];
    if (att.empty()) {
        return not_found;
    };
    return att;
}

int main() {
    int tags, queries;
    cin >> tags;
    cin >> queries;


    string line;
    std::getline(std::cin, line); // skip empty line
    for(int i = 0; i < tags; i++) {
        std::getline(std::cin, line);
        parse_tag(line);
    }

    //show_all(vec);

    for(int i = 0; i < queries; i++) {
        getline(cin, line);
        auto rv = parse_queries(line);
        std::cout << rv << endl;
    }

    return 0;
}

