#include <stdio.h>
#include <string.h>


void showMainMenu() {
    printf("\n========== ONLINE ORDERING SYSTEM ==========\n");
    printf("Select a Category:\n");
    printf("1. Food Items\n");
    printf("2. Electronics\n");
    printf("3. Makeup\n");
    printf("4. Toiletries\n");
    printf("5. Stationary\n");
    printf("6. Exit\n");
    printf("--------------------------------------------\n");
    printf("Enter your choice: ");
}

void foodMenu() {
    printf("---------------- FOOD MENU -----------------\n");
    printf("1. CWU Instant Noodles (Pack of 8) ..... Rs. 160\n"
           "2. CWU Mixed Dal (1Kg) ................. Rs. 120\n"
           "3. CWU Wheat Flour (1Kg) ............... Rs. 45\n"
           "4. CWU Basmati Rice (1Kg) .............. Rs. 150\n"
           "5. CWU Multigrain Biscuits ............. Rs. 60\n"
           "6. CWU Spice Mix ....................... Rs. 80\n"
           "7. CWU Mixed Pickle (1Kg) .............. Rs. 100\n"
           "8. CWU Potato Chips (250g) ............. Rs. 50\n"
           "9. CWU Momos ........................... Rs. 120\n");
           printf("--------------------------------------------\n");
    printf("Enter your choice: ");
}

void electronicsMenu() {
    printf("------------- ELECTRONICS MENU -------------\n");
    
    
    
    printf("1. CWU Night Lamp ....................... Rs. 450\n"
           "2. CWU Hair Dryer ....................... Rs. 1500\n"
           "3. CWU Blender .......................... Rs. 4000\n"
           "4. CWU Television ....................... Rs. 40000\n"
           "5. CWU Washing Machine .................. Rs. 30000\n"
           "6. CWU Fridge ........................... Rs. 25000\n"
           "7. CWU Laptop ........................... Rs. 60000\n"
           "8. CWU Mobile Phone ..................... Rs. 20000\n"
           "9. CWU Tablet ........................... Rs. 15000\n"
           "10. CWU Gaming Station .................. Rs. 50000\n");
           printf("--------------------------------------------\n");
    printf("Enter your choice: ");
}

void makeupMenu() {
    printf("--------------- MAKEUP MENU ----------------\n");
    printf("1. CWU Pink Blush ....................... Rs. 350\n"
           "2. CWU Maroon Lipstick .................. Rs. 400\n"
           "3. CWU Shade 8 Foundation ............... Rs. 1200\n"
           "4. CWU Highlighter ...................... Rs. 600\n"
           "5. CWU Black Eyeliner ................... Rs. 300\n");
           printf("--------------------------------------------\n");
    printf("Enter your choice: ");
}

void toiletriesMenu() {
    printf("\n------------- TOILETRIES MENU ---------------\n");
    printf("1. CWU Brush ............................ Rs. 150\n"
           "2. CWU Bar Soap ......................... Rs. 40\n"
           "3. CWU Detergent (5Kg) ................. Rs. 350\n"
           "4. CWU Air Freshener (500ml) ............ Rs. 120\n"
           "5. CWU Utensil Cleaner (500ml) .......... Rs. 100\n"
           "6. CWU Liquid Soap (500ml) .............. Rs. 80\n"
           "7. CWU Toothpaste (500ml) ............... Rs. 90\n");
           printf("--------------------------------------------\n");
    printf("Enter your choice: ");
}

void stationaryMenu() {
    printf("------------- STATIONARY MENU --------------\n");
    printf("1. CWU Black Pen ......................... Rs. 15\n"
           "2. CWU Blue Pen .......................... Rs. 15\n"
           "3. CWU Multi-colored Pens (12 Pack) ...... Rs. 120\n"
           "4. CWU Ruled Page ........................ Rs. 5\n"
           "5. CWU Graph Page ........................ Rs. 5\n"
           "6. CWU Outline Map of India .............. Rs. 60\n"
           "7. CWU Notebook (500 Pages) .............. Rs. 300\n"
           "8. CWU Eraser ............................ Rs. 10\n"
           "9. CWU Sharpener ......................... Rs. 15\n"
           "10. CWU Scale ............................ Rs. 30\n"
           "11. CWU Geometry Box ..................... Rs. 200\n"
           "12. CWU Stick Adhesive ................... Rs. 40\n");
           printf("--------------------------------------------\n");
    printf("Enter your choice: ");
}

int getPrice(int cat, int item) {
    int priceTable[5][13] = {
        {0,160,120,45,150,60,80,100,50,120,0,0,0},      
        {0,450,1500,4000,40000,30000,25000,60000,20000,15000,50000,0,0}, 
        {0,350,400,1200,600,300,0,0,0,0,0,0,0},       
        {0,150,40,350,120,100,80,90,0,0,0,0,0},        
        {0,15,15,120,5,5,60,300,10,15,30,200,40}        
    };
    if (cat < 1 || cat > 5) return 0;
    if (item < 1 || item > 12) return 0;
    return priceTable[cat-1][item];
}

float getTax(int cat) {
    switch (cat) {
        case 1: return 0.05; 
        case 2: return 0.18;  
        case 3: return 0.12;  
        case 4: return 0.05;  
        case 5: return 0.12;  
        default: return 0;
    }
}

void payment_mode() {
    int mode, valid;
    char upi_id[50];

    printf("\n============= PAYMENT OPTIONS ==============\n");
    printf("1. UPI Payment\n");
    printf("2. Cash on Delivery \n");
    printf("--------------------------------------------\n");
    printf("Enter your choice : ");
    scanf("%d", &mode);

    if (mode == 1) {
        printf("\n---------------- UPI PAYMENT ----------------\n");
        do {
            printf("Enter your UPI ID (e.g., name@upi): ");
            scanf("%s", upi_id);
            valid = (strstr(upi_id, "@") != NULL);
            if (!valid)
                printf(" Invalid UPI ID! Please include '@' (e.g., name@upi)\n\n");
        } while (!valid);
        printf("Verifying UPI ID");
   
  

        printf("\n UPI ID '%s' verified successfully!\n", upi_id);
        printf(" \nPayment completed via UPI.\n");
    }
    else if (mode == 2) {
        printf("\n------------- CASH ON DELIVERY -------------\n");
        printf(" You chose Cash on Delivery.\n");
        printf("Please pay the amount to the delivery person upon receiving your order.\n");
    }
    else {
        printf("\n Invalid Option! Please try again.\n");
        payment_mode();  
        return;
    }

    printf("\n Payment Option Recorded Successfully.\n");
}
float distance_charge() {
    float distance;
    float charge = 0;
    char input[50];
    int valid = 0;
    
    while (!valid) {
        printf("Enter delivery distance (in km): ");
        if (scanf(" %f", &distance) != 1) {
           
            while (getchar() != '\n');
            printf("Error: Please enter a valid number!\n");
            continue;
        }
        
        
        if (distance <= 0) {
            printf("Error: Distance must be greater than 0!\n");
            continue;
        }
        
        valid = 1; 
    }
    
    if (distance <= 2) {
        charge = 100;
    }
    else if (distance <= 5) {
        charge = 150;
    }
    else if (distance <= 10) {
        charge = 200;
    }
    else {
        charge = 200 + ((distance - 10) * 20);
    }
    
    printf("Delivery charge for %.1f km: Rs. %.2f\n", distance, charge);
    return charge;
}

float coupon_code(float total) {
    char code[10];
    float discount = 0;

    printf("\n\nEnter coupon code (CWU10/CWU20) or 'none': ");
    scanf(" %s", code);  
    
    if(strcmp(code, "CWU10") == 0) {
        discount = total * 0.10;
        printf("Coupon Applied: 10%% OFF (Rs. %.2f)\n", discount);
    } 
    else if(strcmp(code, "CWU20") == 0) {
        discount = total * 0.20;
        printf("Coupon Applied: 20%% OFF (Rs. %.2f)\n", discount);
    } 
    else if(strcmp(code, "none") == 0) {
        printf("No coupon applied.\n");
    } 
    else {
        printf("Invalid coupon code.\n");
        return coupon_code(total);
    }

    total -= discount;
    return total;
}

struct OrderItem {
    int category;
    int item;
    int quantity;
    float price;
};

const char* getItemName(int category, int item) {
    switch(category) {
        case 1: 
            switch(item) {
                case 1: return "CWU Instant Noodles";
                case 2: return "CWU Mixed Dal";
                case 3: return "CWU Wheat Flour";
                case 4: return "CWU Basmati Rice";
                case 5: return "CWU Multigrain Biscuits";
                case 6: return "CWU Spice Mix";
                case 7: return "CWU Mixed Pickle";
                case 8: return "CWU Potato Chips";
                case 9: return "CWU Momos";
                default: return "Unknown Item";
            }
        case 2: 
            switch(item) {
                case 1: return "CWU Night Lamp";
                case 2: return "CWU Hair Dryer";
                case 3: return "CWU Blender";
                case 4: return "CWU Television";
                case 5: return "CWU Washing Machine";
                case 6: return "CWU Fridge";
                case 7: return "CWU Laptop";
                case 8: return "CWU Mobile Phone";
                case 9: return "CWU Tablet";
                case 10: return "CWU Gaming Station";
                default: return "Unknown Item";
            }
        case 3: 
            switch(item) {
                case 1: return "CWU Pink Blush";
                case 2: return "CWU Maroon Lipstick";
                case 3: return "CWU Shade 8 Foundation";
                case 4: return "CWU Highlighter";
                case 5: return "CWU Black Eyeliner";
                default: return "Unknown Item";
            }
        case 4: 
            switch(item) {
                case 1: return "CWU Brush";
                case 2: return "CWU Bar Soap";
                case 3: return "CWU Detergent";
                case 4: return "CWU Air Freshener";
                case 5: return "CWU Utensil Cleaner";
                case 6: return "CWU Liquid Soap";
                case 7: return "CWU Toothpaste";
                default: return "Unknown Item";
            }
        case 5: 
            switch(item) {
                case 1: return "CWU Black Pen";
                case 2: return "CWU Blue Pen";
                case 3: return "CWU Multi-colored Pens";
                case 4: return "CWU Ruled Page";
                case 5: return "CWU Graph Page";
                case 6: return "CWU Outline Map of India";
                case 7: return "CWU Notebook";
                case 8: return "CWU Eraser";
                case 9: return "CWU Sharpener";
                case 10: return "CWU Scale";
                case 11: return "CWU Geometry Box";
                case 12: return "CWU Stick Adhesive";
                default: return "Unknown Item";
            }
        default:
            return "Unknown Item";
    }
}

void display_cart(struct OrderItem orders[], int orderCount) {
    if (orderCount == 0) {
        printf("\nCart is empty!\n");
        return;
    }

    printf("----------- Current Cart Items ------------\n");
    for(int i = 0; i < orderCount; i++) {
        printf("%d. %s (%d) - Rs. %.2f\n", 
            i + 1,
            getItemName(orders[i].category, orders[i].item),
            orders[i].quantity,
            orders[i].price * orders[i].quantity
        );
    }
    printf("--------------------------------------------\n");
}

int remove_item(struct OrderItem orders[], int *orderCount, float *total, float *totalTax, int *total_qty) {
    int choice;
    display_cart(orders, *orderCount);
    
    if (*orderCount == 0) {
        return 0;
    }
    
    printf("Enter the number of item to remove (1-%d) or 0 to cancel: ", *orderCount);
    if (scanf("%d", &choice) != 1 || choice < 0 || choice > *orderCount) {
        printf("Invalid choice!\n");
        while (getchar() != '\n');
        return 0;
    }
    
    if (choice == 0) {
        printf("Removal cancelled.\n");
        return 0;
    }
    choice--;
    
    float item_cost = orders[choice].price * orders[choice].quantity;
    float item_tax = getTax(orders[choice].category) * item_cost;
    
    *total -= (item_cost + item_tax);
    *totalTax -= item_tax;
    *total_qty -= orders[choice].quantity;

    printf("Updating cart");
for (int i = 0; i < 3; i++) {
    printf(".");
    fflush(stdout);
    sleep(1);
}
    
    printf("\n\n[-] Removed: %s (%d)\n", 
        getItemName(orders[choice].category, orders[choice].item),
        orders[choice].quantity);
    
    for(int i = choice; i < *orderCount - 1; i++) {
        orders[i] = orders[i + 1];
    }
    (*orderCount)--;
    
    printf("Cart updated successfully!\n");
    display_cart(orders, *orderCount);
    printf("\n============================================\n");
printf("             BACK TO MAIN MENU\n");
printf("============================================\n");
    return 1;
}

void get_feedback() {
    int stars;
    int valid = 0;
    printf("\n--------------------------------------------\n");
    while (!valid) {
        
        printf("Please rate your experience (1-5 stars): ");
        if (scanf("%d", &stars) != 1) {
            
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            continue;
        }
        
        if (stars < 1 || stars > 5) {
            printf("Invalid rating! Please enter a number between 1 and 5.\n");
            continue;
        }
        
        valid = 1;
    }
    
    printf("\nYour rating: ");
    for (int i = 0; i < stars; i++) {
        printf("*");
    }
    for (int i = stars; i < 5; i++) {
        printf("-");
    }
    printf(" (%d/5)\n", stars);
    
    if (stars <= 2) {
        printf("We're sorry about your experience. We'll work to improve!\n");
    } else if (stars <= 4) {
        printf("Thank you for your feedback! We'll keep improving.\n");
    } else {
        printf("Thank you for your excellent rating!\n");
    }
    printf("--------------------------------------------\n");
}



struct Address {
    char name[50];
    char phone[15];
    char house[100];
    char city[50];
    char pincode[10];
};

struct Address take_address_input() {
    struct Address addr;
    printf("\n=========== ENTER DELIVERY DETAILS ==========\n");
      printf("--------------------------------------------\n");
    printf("Enter your name: ");
    scanf(" %[^\n]", addr.name);
    printf("Enter phone number: ");
    scanf("%s", addr.phone);
    printf("Enter house/street: ");
    scanf(" %[^\n]", addr.house);
    printf("Enter city: ");
    scanf(" %[^\n]", addr.city);
    printf("Enter pincode: ");
    scanf("%s", addr.pincode);
    printf("--------------------------------------------\n");
    return addr;
}

void print_address(struct Address addr) {
    printf("\n============ DELIVERY ADDRESS =============\n");
    printf("--------------------------------------------\n");
    printf("Name    : %s\n", addr.name);
    printf("Phone   : %s\n", addr.phone);
    printf("Address : %s, %s - %s\n", addr.house, addr.city, addr.pincode);
    printf("--------------------------------------------\n");
}

int main() {
    int choice, item, qty=0, total_qty=0;
    float total = 0, totalTax = 0;
    char cont = 'y';
    
    struct OrderItem orders[50];
    struct Address userAddress;

    int orderCount = 0;
        printf("\n============================================\n");
        printf("            Welcome to CWU STORE\n");
    printf("============================================\n");

    while(cont == 'y' || cont == 'Y') {
        showMainMenu();
        scanf("%d", &choice);
        if(choice == 6) {
            printf("\nExiting");
            break;
        }

        switch(choice) {
            case 1: foodMenu(); break;
            case 2: electronicsMenu(); break;
            case 3: makeupMenu(); break;
            case 4: toiletriesMenu(); break;
            case 5: stationaryMenu(); break;
            default: printf("Invalid choice!\n"); continue;
        }

        scanf("%d", &item);
        printf("Enter quantity: ");
        scanf("%d", &qty);

        int price = getPrice(choice, item);
        if(price == 0) {
            printf("Invalid selection!\n");
        } else {
            float cost = price * qty;
            float tax = getTax(choice) * cost;
            float total_item = cost + tax;
            total += total_item;
            total_qty += qty;
            totalTax += tax;
            
            orders[orderCount].category = choice;
            orders[orderCount].item = item;
            orders[orderCount].quantity = qty;
            orders[orderCount].price = price;
            orderCount++;
            
            printf("[+] Added to cart: %s (%d)\n", getItemName(choice, item), qty);
            printf("Item cost: Rs. %.2f | Tax: Rs. %.2f | Total: Rs. %.2f\n", cost, tax, total_item);
            printf("--------------------------------------------\n");

        }

        char choice;
        if (orderCount == 0) {
            do {
                printf("\nDo you want to order or not? (y/n): ");
                scanf(" %c", &choice);
                
                if(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
                    printf("Invalid input! Please enter 'y' for yes or 'n' for no.\n");
                }
            } while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
        } else {
            do {
                printf("\nDo you want to:\n");
                printf("1. Order more items (y)\n");
                printf("2. Remove items (r)\n");
                printf("3. Proceed to checkout (n)\n");
                printf("--------------------------------------------\n");
                printf("Enter your choice: ");
                scanf(" %c", &choice);
                
                if(choice != 'y' && choice != 'Y' && choice != 'r' && choice != 'R' && choice != 'n' && choice != 'N') {
                    printf("Invalid input! Please enter 'y' to order more, 'r' to remove items, or 'n' to checkout.\n");
                }
            } while(choice != 'y' && choice != 'Y' && choice != 'r' && choice != 'R' && choice != 'n' && choice != 'N');
            
            if(choice == 'r' || choice == 'R') {
                remove_item(orders, &orderCount, &total, &totalTax, &total_qty);
                choice = 'y'; 
            }
        }
        cont = choice;

    }

    if(total == 0) {
        printf("No items ordered.\n");
        return 0;
    }

    
    float final_total = coupon_code(total);
    userAddress = take_address_input();
    float delivery = distance_charge();
    final_total += delivery;
     

    printf("\n============================================\n");
    printf("                 FINAL BILL\n");
    printf("============================================\n");
    printf("ITEMS ORDERED:\n");
    printf("--------------------------------------------\n");
    for(int i = 0; i < orderCount; i++) {
        printf("%d. %s (%d) - Rs. %.2f\n", 
            i + 1,
            getItemName(orders[i].category, orders[i].item),
            orders[i].quantity,
            orders[i].price * orders[i].quantity
        );
    }
    printf("--------------------------------------------\n");
    printf("Total Items in Cart:               %d\n", total_qty);
    printf("Cost of items:                Rs. %.2f\n", total - totalTax);    
    printf("Subtotal (with tax):          Rs. %.2f\n", total);
    printf("Discount:                     Rs. -%.2f\n", (total - (final_total - delivery)));
    printf("Delivery Charge:              Rs. %.2f\n", delivery);
    printf("--------------------------------------------\n");
    printf("Grand Total Payable:          Rs. %.2f\n", final_total);
    printf("--------------------------------------------\n");
    print_address(userAddress); 
    
    payment_mode();
   
    printf("============================================\n");
    get_feedback();
    printf("\n********************************************\n");
    printf("        THANK YOU FOR SHOPPING WITH CWU    \n");
    printf("              Visit Again Soon!            \n");
    printf("********************************************\n");

    return 0;
}
