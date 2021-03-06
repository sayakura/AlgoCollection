#include <vector>
#include <iostream>

using namespace std;

class disjoint_set {
    vector<pair<int, int>> arr;
    int siz;
        
    public: 
    disjoint_set(int N) {
        arr = vector<pair<int, int>>(N);
        for (int i = 0; i < N; i++) {
            arr[i].first = i;
            arr[i].second = 0;
        }
        siz = N;
    }
    int find(int x) {
        if (arr[x].first != x)
            arr[x].first = find(arr[x].first);
        return arr[x].first;
    }
    void join(int x, int y) {
        int xv = find(x);
        int yv = find(y);
        if (xv == yv)
            return ;
        siz--;
        if (arr[xv].second < arr[yv].second)
            arr[xv].first = yv;
        else if (arr[xv].second > arr[yv].second) 
            arr[yv].first = xv;
        else {
            arr[xv].first = yv;
            arr[xv].second++;
        }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    int size() {
        return siz;
    }
};


class disjoint_set{
    vector<int> parent;
    vector<int> rank;
    unsigned int size;
public:
    disjoint_set(int n) {
        parent.assign(n, 0);
        rank.assign(n, 0);
        size = n;
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int v) {
       while (parent[v] != v){
           parent[v] = parent[parent[v]];
           v = parent[v];
       }
       return v;
    }
    int union_set(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};




const AWS = require('aws-sdk');
//*/ get reference to S3 client 
var s3 = new AWS.S3();
exports.handler =  async (event) => {
     let encodedImage =JSON.parse(event.body).user_avatar;
     let decodedImage = Buffer.from(encodedImage, 'base64');
     var filePath = "avatars/" + event.queryStringParameters.username + ".jpg"
     var params = {
       "Body": decodedImage,
       "Bucket": "find-my-mate-hasangi",
       "Key": filePath  
    };
    s3.upload(params, function(err, data){
       if(err) {
           callback(err, null);
       } else {
           let response = {
        "statusCode": 200,
        "headers": {
            "my_header": "my_value"
        },
        "body": JSON.stringify(data),
        "isBase64Encoded": false
    };
           callback(null, response);
    }
    });
    
};