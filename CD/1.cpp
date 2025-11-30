#include<bits/stdc++.h>
using namespace std;

// Regular expressions for various components
const regex KEYWORD_PATTERN(R"(\b(?:auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|main|namespace|public|private|protected|class|friend|virtual|template|this|new|delete|try|catch|throw|inline|using|export|mutable)\b)");
const regex OPERATOR_PATTERN(R"([+\-*/%=<>!&|^~]|<<|>>|::)");
const regex SPECIAL_SYMBOL_PATTERN(R"([{}();,.\[\]])");
const regex DATA_TYPE_PATTERN(R"(\b(?:int|float|double|char|long|short|void|bool|unsigned)\s+([A-Za-z_][A-Za-z0-9_]*)\b)");

int main() {
    string content, line;
    while (getline(cin, line)) {
        content += line + "\n";   // keep building the full source
    }

    set<string> keywords;
    auto words_begin = sregex_iterator(content.begin(), content.end(), KEYWORD_PATTERN);
    auto words_end = sregex_iterator();
    for (auto i = words_begin; i != words_end; ++i)
        keywords.insert(i->str());

    set<string> identifiers;
    words_begin = sregex_iterator(content.begin(), content.end(), DATA_TYPE_PATTERN);
    for (auto i = words_begin; i != words_end; ++i)
        identifiers.insert(i->str(1));

    for (const auto& keyword : keywords)
        identifiers.erase(keyword);

    set<string> operators;
    words_begin = sregex_iterator(content.begin(), content.end(), OPERATOR_PATTERN);
    for (auto i = words_begin; i != words_end; ++i)
        operators.insert(i->str());

    set<string> special_symbols;
    words_begin = sregex_iterator(content.begin(), content.end(), SPECIAL_SYMBOL_PATTERN);
    for (auto i = words_begin; i != words_end; ++i)
        special_symbols.insert(i->str());

    cout << "=== C/C++ Program Lexical Analysis ===\n\n";

    cout << "Keywords found (" << keywords.size() << "):\n";
    for (const auto& k : keywords) cout << k << " ";
    cout << "\n\n";

    cout << "Identifiers found (" << identifiers.size() << "):\n";
    for (const auto& id : identifiers) cout << id << " ";
    cout << "\n\n";

    cout << "Operators found (" << operators.size() << "):\n";
    for (const auto& op : operators) cout << op << " ";
    cout << "\n\n";

    cout << "Special symbols found (" << special_symbols.size() << "):\n";
    for (const auto& sym : special_symbols) cout << sym << " ";
    cout << "\n";
    return 0;
}
