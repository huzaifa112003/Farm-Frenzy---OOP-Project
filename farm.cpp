#include<iostream>
#include "farm.hpp"
#include <chrono>
#include <thread>

int lastProductTime = 0;


int farmfrenzy::currentMoney(){
    return money;
}

void farmfrenzy::drawObjects(){
    
    for (int i = 0; i < animals.size(); i++) { //iterate over the animals vector that stores animal pointer.
        animals[i] -> draw(gRenderer, assets);  //call draw function of each animal
        animals[i] -> move();//call move function for each animal
        
        // check if it's time to create a product for this animal
        int currentTime = SDL_GetTicks() / 1000; //gives us time until sdl has started running in secs.
        int secs= 15+ rand()%40; //generating a random value in secs for creating the product.
        if (currentTime - lastProductTime >= secs) {
            // create a product for this animal
            food* product = animals[i]->createProduct(gRenderer, assets); //call createproduct of each animal and makeit a food pointer since createproduct is returning a food pointer.
            products.push_back(product); //push in products vector.
            lastProductTime = currentTime; //make last product time equal to the time when the last product was created i.e current time. 
        }
    }
}



void farmfrenzy::createChicken(int x, int y){
    if((x>=0 && x<=46) && (y>=0 && y<=52)){ //when the player buys a chicken
        x= 152+ rand()%630; //creating random x so that it does not draw at the same place every time.
        y= 124+ rand()%300; //creating random y so that it does not draw at the same place every time.
        if((y>125 && y<450) && (x>142 && x<812)){ //condition to restrict animals in the farm area.
            Animal *murghi = new chicken(gRenderer, assets, x, y); // chicken is drawn. Thus animal vector assigned to the structure object.
            animals.push_back(murghi); // pushed back into vector 
            money-=100;
        }  
        std::cout<<"Chicken created at: "<<x<<" -- "<<y<<std::endl;
    }
}
void farmfrenzy::createPig(int x, int y){
    if((x>=50 && x<=94) && (y>=3 && y<=52)){ //when the player buys a pig
        int xx= 152+ rand()%630; //creating random x so that it does not draw at the same place every time.
        x=xx;
        int yy= 124+ rand()%300; //creating random y so that it does not draw at the same place every time.
        y=yy;
        if((y>125 && y<450) && (x>142 && x<812)){
            Animal *piggy = new Pig(gRenderer, assets, x, y); // pig is drawn. Thus animal vector assigned to the structure object.
            animals.push_back(piggy); // pushed back into vector 
            money-=200;
        }  
        std::cout<<"Pig created at: "<<x<<" -- "<<y<<std::endl;
    }
}

void farmfrenzy::createCow(int x, int y){
    if((x>=95 && x<=141) && (y>=0 && y<=52)){ //when the player will buy a cow
        int xx= 152+ rand()%630; //creating random x so that it does not draw at the same place every time.
        x=xx;
        int yy= 124+ rand()%300; //creating random y so that it does not draw at the same place every time.
        y=yy;
        if((y>125 && y<450) && (x>142 && x<812)){ // condition that makes sure animals only appear in the farm area.
            Animal* gaye = new cow(gRenderer, assets, x, y); // cow is drawn. Thus animal vector assigned to the structure object.
            animals.push_back(gaye); // pushed back into vector     
            money-=300;
        }
        std::cout<<"Cow created  at: "<<x<<" -- "<<y<<std::endl;
    }
}

void farmfrenzy::createSheep(int x, int y){
    
    if((x>=144 && x<=193) && (y>=0 && y<=52)){ //when the player will buy a sheep
        
        int xx= 152+ rand()%630; //creating random x so that it does not draw at the same place every time.
        x=xx;
        int yy= 124+ rand()%300; //creating random y so that it does not draw at the same place every time.
        y=yy;
        if((y>125 && y<450) && (x>142 && x<812)){ // condition that makes sure animals only appear in the farm area.
            Animal* sheepu = new sheep(gRenderer, assets, x, y); // sheep is drawn. Thus animal vector assigned to the structure object.
            animals.push_back(sheepu); // pushed back into vector    
            money-=150; 
        }
        std::cout<<"Sheep created at: "<<x<<" -- "<<y<<std::endl;

    }

}


farmfrenzy::farmfrenzy(SDL_Renderer *renderer, SDL_Texture *asset, int x, int y):  //constructor of farmfrenzy object.
        gRenderer(renderer),
        assets(asset){ 
            last_product_time = std::chrono::system_clock::now(); //set the time when last product was made to the time at that moment.
            }

void farmfrenzy::drawProducts(){
    for (int i = 0; i < products.size(); i++) { //iterate over the products array
        products[i]->draw(gRenderer, assets); //call draw function of each product which further calls draw of either egg, milk, meat or wool.
    }
}

int farmfrenzy::collectedProducts(){
    return countProduct;
}

void farmfrenzy::removeProduct(int x, int y){
    std::cout << "removeProduct called with x = " << x << " and y = " << y << std::endl;
    // iterate over all the products
    for (int i = 0; i < products.size(); i++) {
        // get the position and size of the product
        int product_x = products[i]->getX();
        int product_y = products[i]->getY();
        int product_w = products[i]->getWidth();
        int product_h = products[i]->getHeight();
        
        // check if the mouse click is inside the product
        if (x >= product_x && x <= product_x + product_w && y >= product_y && y <= product_y + product_h) {
            
            // check type of the product being deleted and increment money accordingly.

            if(products[i]->type()=='e'){
            money+=100;
            
            }
            else if(products[i]->type()=='m'){
            money+=250;
           
            }
            else if(products[i]->type()=='g'){
            money+=350;
            }
            else if(products[i]->type()=='w'){
            money+=500;
            }
            // remove the product from the vector and delete it from memory
            delete products[i];
            products.erase(products.begin() + i);
            countProduct++; //increment using operator overloading
            collectedProducts();
            
            break; // break out of the loop after removing the product
        }
    }
}


farmfrenzy::~farmfrenzy(){ //destructor
    for (int i = 0; i < animals.size(); i++) { //iterate over animals vector.
    delete animals[i]; //delete all animal pointers that will call animal class's destructor
    animals.erase(animals.begin() + i); //erase from memory the animals vector
    cout<<"destructing animal"<<endl;}


     // below lines will only show output if the player has not collected the products and game ends.
    for (int i = 0; i < products.size(); i++) { //iterate over products vector.
    delete products[i]; //delete all food pointers that will call food class's destructor
    products.erase(products.begin() + i); //erase from memory the products vector
    cout<<"destructing product"<<endl;
}
}



