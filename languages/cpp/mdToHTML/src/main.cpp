#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
  ifstream sourceFile("source.md");
  if(!sourceFile){
    cout << "couldn't open the sourcefile. Closing\n";
    exit(-1);
  }
  string sourceLine;
  cout << "Translating Markdown to HTML...\n";
  while(!sourceFile.eof()){
    sourceLine = getline(sourceFile, sourceLine);
    sourceLine = parseMdToHtml(sourceLine);
    printLine(sourceLine);
  }
  cout << "Finished...\n";
  return 0;
}

//parse
// headers - leading "#"
//italics with encapsulating "*"
//bold with encapsulating "**"
//strikethrough with encapsulating "~~"
//unordered and ordered lists - 
string parseMdToHtml(string sourceLine){
  for(int i = 0; i < sourceLine.size(); i++){

  }
}
