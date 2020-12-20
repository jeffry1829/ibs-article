# ibs-article
Original Idea: https://physionet.org/content/ibs/1.0.0/ or  
Yang AC, Peng C-K, Yien H-W, Goldberger AL: Information categorization approach to literary authorship disputes. Physica A 2003, 329:
473–483.

I just implemented it.

### To run the program to determine the distance between two articles
under Linux:
```
./run file1.txt file2.txt
```
Please ensure the locale of two files are the same.

### Compile
```
g++ ibs-article.cpp -o run
```