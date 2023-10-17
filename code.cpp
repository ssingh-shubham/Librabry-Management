#include <iostream>
#include <string>
#include <vector>

class LibraryItem;
class LibraryUser;

class LibraryItem 
{
public:
    LibraryItem(const std::string& item_id, const std::string& title) : item_id_(item_id), title_(title), availability_(true) {}

    virtual ~LibraryItem() {}

    const std::string& getItemID() const 
    { 
        return item_id_; 
        
    }
    const std::string& getTitle() const 
    { 
        return title_; 
    }
    bool isAvailable() const 
    { 
        return availability_;
    }

    virtual void displayDetails() const = 0;

    friend class LibraryManager;

protected:
    std::string item_id_;
    std::string title_;
    bool availability_;
};

class Book : public LibraryItem 
{
public:
    Book(const std::string& item_id, const std::string& title, const std::string& author, const std::string& isbn)
        : LibraryItem(item_id, title), author_(author), isbn_(isbn) {}

    void displayDetails() const override 
    {
        std::cout << "Book ID: " << item_id_ << ", Title: " << title_ << ", Author: " << author_ << ", ISBN: " << isbn_ << std::endl;
    }

private:
    std::string author_;
    std::string isbn_;
};

class DVD : public LibraryItem 
{
public:
    DVD(const std::string& item_id, const std::string& title, const std::string& director, const std::string& runtime)
        : LibraryItem(item_id, title), director_(director), runtime_(runtime) {}

    void displayDetails() const override 
    {
        std::cout << "DVD ID: " << item_id_ << ", Title: " << title_ << ", Director: " << director_ << ", Runtime: " << runtime_ << std::endl;
    }

private:
    std::string director_;
    std::string runtime_;
};

class Magazine : public LibraryItem 
{
public:
    Magazine(const std::string& item_id, const std::string& title, const std::string& editor, const std::string& publication_date)
        : LibraryItem(item_id, title), editor_(editor), publication_date_(publication_date) {}

    void displayDetails() const override 
    {
        std::cout << "Magazine ID: " << item_id_ << ", Title: " << title_ << ", Editor: " << editor_ << ", Publication Date: " << publication_date_ << std::endl;
    }

private:
    std::string editor_;
    std::string publication_date_;
};

class LibraryUser 
{
public:
    LibraryUser(const std::string& user_id, const std::string& name) : user_id_(user_id), name_(name) {}

    const std::string& getUserID() const 
    { 
        return user_id_; 
    }
    const std::string& getName() const 
    { 
        return name_;
    }

    friend class LibraryManager;

private:
    std::string user_id_;
    std::string name_;
    std::vector<LibraryItem*> checked_out_items_;
};

class LibraryManager 
{
public:
    static bool checkOutItem(LibraryItem* item, LibraryUser* user) 
    {
        if (item->availability_) 
        {
            item->availability_ = false;
            user->checked_out_items_.push_back(item);
            return true;
        }
        return false;
    }

    static bool returnItem(LibraryItem* item, LibraryUser* user) 
    {
        for (size_t i = 0; i < user->checked_out_items_.size(); i++) 
        {
            if (user->checked_out_items_[i] == item) 
            {
                item->availability_ = true;
                user->checked_out_items_.erase(user->checked_out_items_.begin() + i);
                return true;
            }
        }
        return false;
    }
};

int main() 
{
    std::vector<LibraryItem*> items;
    std::vector<LibraryUser> users;

    while (true) 
    {
        std::cout << "\nLibrary Management System Menu:" << std::endl;
        std::cout << "1. Add a Book" << std::endl;
        std::cout << "2. Add a DVD" << std::endl;
        std::cout << "3. Add a Magazine" << std::endl;
        std::cout << "4. Add a User" << std::endl;
        std::cout << "5. Check Out Item" << std::endl;
        std::cout << "6. Return Item" << std::endl;
        std::cout << "7. Display Available Items" << std::endl;
        std::cout << "8. Delete Item" << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) 
        {
            case 1: 
            {
                std::string item_id, title, author, isbn;
                std::cout << "Enter Book ID: ";
                std::cin >> item_id;
                std::cout << "Enter Book Title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter Author: ";
                std::getline(std::cin, author);
                std::cout << "Enter ISBN: ";
                std::cin >> isbn;
                items.push_back(new Book(item_id, title, author, isbn));
                break;
            }
            case 2: 
            {
                std::string item_id, title, director, runtime;
                std::cout << "Enter DVD ID: ";
                std::cin >> item_id;
                std::cout << "Enter DVD Title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter Director: ";
                std::getline(std::cin, director);
                std::cout << "Enter Runtime: ";
                std::cin >> runtime;
                items.push_back(new DVD(item_id, title, director, runtime));
                break;
            }
            case 3: 
            {
                std::string item_id, title, editor, publication_date;
                std::cout << "Enter Magazine ID: ";
                std::cin >> item_id;
                std::cout << "Enter Magazine Title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter Editor: ";
                std::getline(std::cin, editor);
                std::cout << "Enter Publication Date: ";
                std::cin >> publication_date;
                items.push_back(new Magazine(item_id, title, editor, publication_date));
                break;
            }
            case 4: 
            {
                std::string user_id, name;
                std::cout << "Enter User ID: ";
                std::cin >> user_id;
                std::cout << "Enter User Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                users.push_back(LibraryUser(user_id, name));
                break;
            }
            case 5: 
            {
                std::string user_id, item_id;
                std::cout << "Enter User ID: ";
                std::cin >> user_id;
                std::cout << "Enter Item ID: ";
                std::cin >> item_id;

                LibraryUser* user = nullptr;
                LibraryItem* item = nullptr;

                for (size_t i = 0; i < users.size(); i++) 
                {
                    if (users[i].getUserID() == user_id) 
                    {
                        user = &users[i];
                        break;
                    }
                }

                for (size_t i = 0; i < items.size(); i++) 
                {
                    if (items[i]->getItemID() == item_id) 
                    {
                        item = items[i];
                        break;
                    }
                }

                if (user && item) 
                {
                    if (LibraryManager::checkOutItem(item, user)) 
                    {
                        std::cout << "Item checked out successfully." << std::endl;
                    } 
                    else 
                    {
                        std::cout << "Item is not available for checkout." << std::endl;
                    }
                } 
                else 
                {
                    std::cout << "User or item not found." << std::endl;
                }
                break;
            }
            case 6: 
            {
                std::string user_id, item_id;
                std::cout << "Enter User ID: ";
                std::cin >> user_id;
                std::cout << "Enter Item ID: ";
                std::cin >> item_id;

                LibraryUser* user = nullptr;
                LibraryItem* item = nullptr;

                for (size_t i = 0; i < users.size(); i++) 
                {
                    if (users[i].getUserID() == user_id) 
                    {
                        user = &users[i];
                        break;
                    }
                }

                for (size_t i = 0; i < items.size(); i++) 
                {
                    if (items[i]->getItemID() == item_id) 
                    {
                        item = items[i];
                        break;
                    }
                }

                if (user && item) {
                    if (LibraryManager::returnItem(item, user)) 
                    {
                        std::cout << "Item returned successfully." << std::endl;
                    } 
                    else 
                    {
                        std::cout << "Item could not be returned." << std::endl;
                    }
                } 
                else 
                {
                    std::cout << "User or item not found." << std::endl;
                }
                break;
            }
            case 7: 
            {
                std::cout << "\nAvailable Items:" << std::endl;
                for (size_t i = 0; i < items.size(); i++) 
                {
                    if (items[i]->isAvailable()) 
                    {
                        items[i]->displayDetails();
                    }
                }
                break;
            }
            case 8: 
            {
                std::cout << "\nEnter Item ID to delete: ";
                std::string item_id_to_delete;
                std::cin >> item_id_to_delete;

                // Find the item to delete
                size_t index_to_delete = items.size();
                for (size_t i = 0; i < items.size(); i++) 
                {
                    if (items[i]->getItemID() == item_id_to_delete) 
                    {
                        index_to_delete = i;
                        break;
                    }
                }

                if (index_to_delete < items.size()) 
                {
                    delete items[index_to_delete];
                    items.erase(items.begin() + index_to_delete);
                    std::cout << "Item deleted successfully." << std::endl;
                } 
                else 
                {
                    std::cout << "Item not found." << std::endl;
                }
                break;
            }
            case 9: 
            {
                std::cout << "\nExit Options:" << std::endl;
                std::cout << "1. Confirm" << std::endl;
                std::cout << "2. Delete All Items and Exit" << std::endl;
                std::cout << "3. Cancel" << std::endl;
                std::cout << "Enter your choice: ";

                int exitChoice;
                std::cin >> exitChoice;

                switch (exitChoice) 
                {
                    case 1:
                        // Clean up dynamically allocated items
                        for (size_t i = 0; i < items.size(); i++) 
                        {
                            delete items[i];
                        }
                        return 0;
                    case 2:
                        // Delete all items and exit
                        for (size_t i = 0; i < items.size(); i++) 
                        {
                            delete items[i];
                        }
                        return 0;
                    case 3:
                        std::cout << "Exit canceled." << std::endl;
                        break;
                    default:
                        std::cout << "Invalid exit option. Please try again." << std::endl;
                }
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
