/*can you read this Hector?

124

2367

1223467
http://collabedit.com/e3jhp
*/

int* mergeSorted(int a[], int b[]){
    int len1 = a.length();
    int len2 = b.length();
    if(len1 == 0 && len2 == 0)
        return NULL;
    int* result = new int[len1+len2];
    
    int i =0, j = 0, k = 0;
    // While a has values and b has values
    while( i < len1 && j < len2){
        // Compare value of array a and array b
        // Copy min(a[i], b[j]) into result[k]
        // increment i or j, increment k
        
        if(a[i] < b[j]){
            result[k] = a[i];
            i++;
        }
        else{
            result[k] = b[j];
            j++;
        }
        k++;
    }
    while(i < len1){
        result[k] = a[i];
        i++; k++;
    }
    while(j < len2){
        result[k] = b[j];
        j++; k++;
    }
    return result;
}
int main(){
}