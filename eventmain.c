#include <stdio.h>
#include <stdlib.h>  // For rand() function
#include <string.h>

// Function to get service cost based on event type
int getServiceCost(int choice) {
    switch (choice) {
        case 1: return 5000000; // Wedding
        case 2: return 1000000; // Birthday
        case 3: return 2000000; // Reunion
        case 4: return 1500000; // Party
        default: return 0;
    }
}

// Function to get cost based on number of people
int getPeopleCost(int num_people) {
    if (num_people >= 100 && num_people <= 150) {
        return 1500000;
    } else if (num_people >= 200 && num_people <= 300) {
        return 3000000;
    } else if (num_people >= 300 && num_people <= 500) {
        return 5000000;
    }
    return 0;
}

// Function to get decoration cost based on style
int getDecorationCost(int decoration_choice) {
    switch (decoration_choice) {
        case 1: return 5000 + (rand() % 1000); // Fancy
        case 2: return 3000 + (rand() % 1000); // Aesthetic
        case 3: return 2000 + (rand() % 1000); // Festive
        case 4: return 6000 + (rand() % 2000); // Floral
        case 5: return 9000 + (rand() % 1000); // Customize
        default: return 0;
    }
}

// Function to suggest cost-saving options
void suggestCostSavingOptions() {
    printf("\nSuggestions to reduce expenses:\n");
    printf("1. Consider reducing the number of guests to lower the people cost.\n");
    printf("2. Choose a more affordable decoration style (e.g., 'Aesthetic' or 'Festive').\n");
    printf("3. Reduce the level of customization in the decoration style.\n");
    printf("4. Check if you can move the event to a less expensive venue.\n");
}

// Function to handle additional services based on event type
int handleAdditionalServices(int choice) {
    int additional_cost = 0;
    int option_choice;

    printf("\nDo you want any of the following additional services?\n");

    switch (choice) {
        case 1: // Wedding
            printf("1. Sangeet (40000 INR)\n");
            printf("2. Mehendi (80000 INR)\n");
            printf("3. Reception (100000 INR)\n");
            break;
        case 2: // Birthday
            printf("1. Performers (30000 INR)\n");
            printf("2. Magic Shows (50000 INR)\n");
            printf("3. Music Performances (30000 INR)\n");
            break;
        case 3: // Reunion
            printf("1. Music (10000 INR)\n");
            printf("2. Live Singer Performances (30000 INR)\n");
            break;
        case 4: // Party
            printf("1. DJ (30000 INR)\n");
            printf("2. Dance Floor (10000 INR)\n");
            printf("3. Bar (60000 INR)\n");
            break;
    }

    printf("Enter your choice (1-3 or 0 to skip): ");
    scanf("%d", &option_choice);

    switch (option_choice) {
        case 1:
            if (choice == 1) additional_cost += 40000; // Wedding - Sangeet
            else if (choice == 2) additional_cost += 30000; // Birthday - Performers
            else if (choice == 3) additional_cost += 10000; // Reunion - Music
            else if (choice == 4) additional_cost += 30000; // Party - DJ
            break;
        case 2:
            if (choice == 1) additional_cost += 80000; // Wedding - Mehendi
            else if (choice == 2) additional_cost += 50000; // Birthday - Magic Shows
            else if (choice == 3) additional_cost += 30000; // Reunion - Live Singer
            else if (choice == 4) additional_cost += 10000; // Party - Dance Floor
            break;
        case 3:
            if (choice == 1) additional_cost += 100000; // Wedding - Reception
            else if (choice == 2) additional_cost += 30000; // Birthday - Music
            else if (choice == 3) additional_cost += 30000; // Reunion - Live Singer
            else if (choice == 4) additional_cost += 60000; // Party - Bar
            break;
        case 0:
            printf("No additional service selected.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return additional_cost;
}

int main() {
    char name[100], address[200], city[100];
    char date[20], time[10], am_pm[3];
    int num_people, base_cost, people_cost, decoration_cost, total_cost, additional_cost;
    float budget;
    int service_choice, decoration_choice;

    // Welcome message and input details
    printf("Welcome to Event Management Website!\n\n");

    // Get user's personal details
    printf("Please enter your name: ");
    scanf(" %[^\n]%*c", name);  // Read the full name including spaces

    printf("Please enter your address: ");
    scanf(" %[^\n]%*c", address);  // Read the full address including spaces

    printf("Please enter your city: ");
    scanf(" %[^\n]%*c", city);  // Read the full city name including spaces

    printf("\nThank you, %s! Let's get started with planning your event.\n\n", name);

    // Get service type with options numbered
    printf("Please choose a service type:\n");
    printf("1. Wedding (5000000 INR)\n");
    printf("2. Birthday (1000000 INR)\n");
    printf("3. Reunion (2000000 INR)\n");
    printf("4. Party (1500000 INR)\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &service_choice);

    // Get base cost based on service type
    base_cost = getServiceCost(service_choice);
    if (base_cost == 0) {
        printf("Invalid service type.\n");
        return 1;
    }

    printf("Service cost for your choice is %d INR.\n", base_cost);

    // Ask for number of people
    printf("\nApproximate number of people: ");
    scanf("%d", &num_people);

    // Get cost based on number of people
    people_cost = getPeopleCost(num_people);
    printf("People cost for %d people is %d INR.\n", num_people, people_cost);

    // Ask for event date and time
    printf("\nEnter the date of the event (e.g., 2024-12-25): ");
    scanf("%s", date);
    
    printf("Enter the time of the event (e.g., 6:00 PM): ");
    scanf("%s %s", time, am_pm);  // Read the time and AM/PM

    // Handle additional services based on event type
    additional_cost = handleAdditionalServices(service_choice);

    // Get decoration style with options numbered
    printf("\nChoose a decoration style:\n");
    printf("1. Fancy (5000 - 6000 INR)\n");
    printf("2. Aesthetic (3000 - 4000 INR)\n");
    printf("3. Festive (2000 - 3000 INR)\n");
    printf("4. Floral (6000 - 8000 INR)\n");
    printf("5. Customize your own decorations (9000 INR)\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &decoration_choice);

    // Get decoration cost
    decoration_cost = getDecorationCost(decoration_choice);
    printf("Decoration cost for your chosen style is %d INR.\n", decoration_cost);

    // Ask for budget
    printf("\nEnter your budget (in INR): ");
    scanf("%f", &budget);

    // Calculate total cost
    total_cost = base_cost + people_cost + decoration_cost + additional_cost;

    // Display total cost
    printf("\nTotal cost for your event is %d INR.\n", total_cost);

    // Suggest cost-saving options if the total exceeds the budget
    if (total_cost > budget) {
        printf("\nThe total cost exceeds your budget. Here are some suggestions to reduce the cost:\n");
        suggestCostSavingOptions();
    }

    return 0;
}
