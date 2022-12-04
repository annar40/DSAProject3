
#include <string>
#include <sstream>
#include <iostream>



class unordered_map{
  private:
    list<pair<int,int>> *buckets;
    int bucket_size;
    int total_elements;
    float max_load_factor;
}

int hash(int key) {
  int hashed_key = strongHashingFunction(key)
  return hashed_key % bucket_size;
}

int strongHashingFunction(int key){
 return key % 10;
}

list<int>::iterator find(int key){
  for(auto& i : buckets[hash(key)]) {
    if(i->first == key){
      return i;
    }
  }
  return buckets[hashed_key].end();
}


void insert(int key, int val){
  auto it = find(key);
  if(it != buckets[hash(key)].end()){
    it->second = val;
    return;
  }
  buckets[hash(key)].push_back({key,val});
  total_elements++;
  rehashIfNeeded();
}

void delete(int key){
  auto it = find(key)
  if(it != buckets[hash(key)].end()){
    buckets[hash(key)].erase(it);
    total_elements--;
  }
}


void rehashIfNeeded(){
  if(total_elements/bucket_size <= max_load_factor){
    return;
  }
  bucket_size *= 2;
  auto new_buckets = new list<pair<int,int>>[bucket_size];
  for(int i = 0; i < bucket_size/2; i++){
    for(auto& kv_itr: buckets[i]){
      new_buckets[hash(kv_itr->first)].push_back(*kv_itr);
    }
  }
  delete[] buckets;
  buckets = new_buckets;
}



int main()
{
    
    
    
    
    return 0;



}