## Explanation
```shell
In this class implementation histogram of the image is calculated and compared with similar objects histogram to see
the performance of histogram. Histograms are created based on counting the meaningful data such as how many red color 
is presented in the image.
```
### Run
```shell
g++ main.cpp -o output -std=c++11 `pkg-config --cflags --libs opencv`
./output
```
### Output
   
 ![test1](https://user-images.githubusercontent.com/94297285/185891226-76306130-0f9c-4c73-8158-29378f93c614.png)
```shell    
Methods and Results (%):
   Correlation: 0.828934 Chi-square: 14.8917 Intersection: 3.79908 Bhattacharyya: 0.42884
```      
![test2](https://user-images.githubusercontent.com/94297285/185891711-ffb5dfa2-1c17-4f8b-aa7d-57ebbcd4f8ec.png)

    Methods and Results (%):
      Correlation: 0.773925 Chi-square: 6.77688 Intersection: 4.65409 Bhattacharyya: 0.345393
    
## Observation
```shell
As it can be seen from results of the comparison between 10 kuruş and 10 kuruş is similar to comparison between 10 kuruş 
and 5 kuruş implying that it is not a good way to check the only the histogram for similarity.
```
#### Source
```shell
https://docs.opencv.org/3.4/d8/dbc/tutorial_histogram_calculation.html
```
