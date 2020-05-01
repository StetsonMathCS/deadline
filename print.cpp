void printDeadline(map<string,string> deadline) {
  string deadlineName = deadline.begin()->first;
  string deadlineDate = deadline.begin()->second;
  string timeDifference = strdelta(strtot(deadlineDate));
  cout<<deadlineName<<" - "<<deadlineDate<<" "<<timeDifference<<endl;
}

void printDeadlines(vector<map<string,string>> deadlines) {
  int i = 1;
  vector<map<string,string>>::iterator it;

  for(it=deadlines.begin();it!=deadlines.end();it++) {
    cout<<i<<". ";
    printDeadline(*it);
  }
}
