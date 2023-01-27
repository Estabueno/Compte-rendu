#include "shop.h"
#include "fstream"

void Gestion_Shop(Shop& s, int& choice)
{

    Product p1("PS5","console de jeu",9,550);
    Product p2("machine_à_laver","5kg,Ecran LCD,800 tours/min",5,300);
    Product p3("verre","A pied en Crystal",200,400);
    Product p4("Télévision","Ecran plat 4k",20,1200);
    Product p5("Canapé","En cuir rouge",7,150);
    int product,quantity = 0;
    std::string name;
    do
    {
        std::cout << "Veuillez entrer le numéro correspondant à l'option souhaitée" << std::endl;
        std::cin >> choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0);
    switch(choice)
    {
    case 1:
        std::cout << "Vous avez choisi l'ajout d'un produit" << std::endl << std::endl;
        std::cout << "Les produits disponibles pour l'ajout sont : " << std::endl << std::endl;
        std::cout << "(1) " << p1 << "(2) " << p2 << "(3) " << p3 << "(4) " << p4 << "(5) " << p5 << std::endl;
        do
        {
            std::cout << "Veuillez entrer le numéro correspondant au produit souhaité" << std::endl;
            std::cin >> product;
        }while(product != 1 && product != 2 && product != 3 && product != 4 && product != 5);
        switch(product)
        {
        case 1:
            s.addProduct(p1);
            break;
        case 2:
            s.addProduct(p2);
            break;
        case 3:
            s.addProduct(p3);
            break;
        case 4:
            s.addProduct(p4);
            break;
        case 5:
            s.addProduct(p5);
            break;
        }
        break;
    case 2:
        std::cout << "Vous avez choisi l'affichage des produits" << std::endl << std::endl;
        s.displayProduct();
        break;
    case 3:
        std::cout << "Vous avez choisi l'affichage des produits" << std::endl << std::endl;
        std::cout << "Veuillez indiquer le nom du produit a affiché" << std::endl;
        std::cout << "Nom : "; std::cin >> name;
        std::cout << std::endl;
        s.displayProduct(name);
        break;
    case 4:
        std::cout << "Vous avez choisi la mise à jour des quantités" << std::endl << std::endl;
        if(s.getProduct().size() != 0)
        {
            std::cout << "Voici les quantités disponibles pour chaque produit : " << std::endl << std::endl;
            for(unsigned i = 0; i < s.getProduct().size(); ++i)
            {
                std::cout << s.getProduct().at(i).getTitle() << " : " << s.getProduct().at(i).getQuantity() << std::endl;
            }
            std::cout << std::endl << "Veuillez sélectionner le nom et la quantité du produit que vous voulez modifier" << std::endl;
            std::cout << "Nom : "; std::cin >> name;
            do
            {
                std::cout << "Quantité : "; 
                std::cin >> quantity;
            } while (quantity < 0);
            std::cout << std::endl;
            s.updateQuantity(name,quantity);
        }
        else
            std::cout << "Il n'y a pour l'instant aucun produit dans le magasin" << std::endl << std::endl;
        break;
    }
}

void Gestion_Clients(Shop& s, int& choice)
{
    bool ok = true;
    Client c1("1637373","Salim","Mansouri");
    Client c2("8277641", "Adrien", "Jacquet Cretides");
    Client c3("8765265","Pierre","Desbruns");
    int user,quantity = 0;
    std::string name_or_id;
    std::string title;
    do
    {
        std::cout << "Veuillez entrer le numéro correspondant à l'option souhaitée" << std::endl;
        std::cin >> choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 0);
    switch(choice)
    {
    case 1:
        std::cout << "Vous avez choisi l'ajout d'un utilisateur" << std::endl << std::endl;
        std::cout << "Les utilisateurs disponibles pour l'ajout sont : " << std::endl << std::endl;
        std::cout << "(1) " << c1 << "(2) " << c2 << "(3) " << c3 << std::endl;
        do
        {
            std::cout << "Veuillez entrer le numéro correspondant au client souhaité" << std::endl;
            std::cin >> user;
        }while(user != 1 && user != 2 && user != 3);
        switch(user)
        {
        case 1:
            s.addClient(c1);
            break;
        case 2:
            s.addClient(c2);
            break;
        case 3:
            s.addClient(c3);
            break;
        }
        break;
    case 2:
        std::cout << "Vous avez choisi l'affichage des utlisateurs" << std::endl << std::endl;
        s.displayClient();
        break;
    case 3:
        std::cout << "Vous avez choisi l'affichage d'un utilisateur par son nom ou son id " << std::endl << std::endl;
        std::cout << "Nom ou Id : "; std::cin >> name_or_id;
        std::cout << std::endl;
        s.displayClient(name_or_id);
        break;
    case 4:
        std::cout << "Vous avez choisi l'ajout d'un produit au panier d'achat " << std::endl << std::endl;
        if(s.getClient().size() != 0)
        {
            std::cout << "Les clients et les produits présents dans le magasin sont : " << std::endl << std::endl;
            s.displayClient();
            s.displayProduct();
            std::cout << "Veuillez entrer le nom ou l'id du client souhaité ainsi que le nom du produit" << std::endl;
            std::cout << "Nom ou Id : "; std::cin >> name_or_id;
            std::cout << "Nom du produit : "; std::cin >> title;
            do
            {
                std::cout << "Quantité souhaitée : "; 
                std::cin >> quantity;
            } while (quantity < 0);
            for(unsigned i = 0; i < s.getProduct().size(); ++i)
            {
                for(unsigned j = 0; j < s.getClient().size(); ++j)
                {
                    if(((s.getClient().at(j).getName() == name_or_id) || (s.getClient().at(j).getId() == name_or_id)) && s.getProduct().at(i).getTitle() == title)
                    {
                        s.addShoppingCart(s.getClient().at(j),s.getProduct().at(i), quantity);
                        ok = false;
                    }
                }
            }
            if(ok)
                std::cout << std::endl << "Le nom/id du client ou le nom du produit n'est pas correct ou ils ne sont pas présent dans le magasin" << std::endl;
            std::cout << std::endl;
        }
        else
            std::cout << "Il n'y a pour l'instant aucun Client dans le magasin" << std::endl << std::endl;
        break;
    case 5:
        std::cout << "Vous avez choisi la supression d'un produit au panier d'achat " << std::endl << std::endl;
        if(s.getClient().size() != 0)
        {
            std::cout << "Les Clients et leurs paniers d'achats sont : " << std::endl << std::endl;
            s.displayShoppingCart();
            std::cout << "Veuillez entrer le nom ou l'id du client souhaité ainsi que le nom du produit" << std::endl;
            std::cout << "Nom ou Id : "; std::cin >> name_or_id;
            std::cout << "Nom du produit : "; std::cin >> title;
            for(unsigned i = 0; i < s.getProduct().size(); ++i)
            {
                for(unsigned j = 0; j < s.getClient().size(); ++j)
                {
                    if(((s.getClient().at(j).getName() == name_or_id) || (s.getClient().at(j).getId() == name_or_id)) && s.getProduct().at(i).getTitle() == title)
                    {
                        s.eraseShoppingCart(s.getClient().at(j),s.getProduct().at(i));
                        ok = false;
                    }
                }
            }
            if(ok)
                std::cout << std::endl << "Le nom/id du client ou le nom du produit n'est pas correct ou ils ne sont pas présent dans le magasin" << std::endl;
            std::cout << std::endl;
        }
        else
            std::cout << "Il n'y a pour l'instant aucun Client dans le magasin" << std::endl << std::endl;
        break;
    case 6:
        std::cout << "Vous avez choisi la mise à jour des quantités" << std::endl;
        if(s.getClient().size() != 0)
        {
            std::cout << "Voici les quantités des produit dans chaque panier d'achat: " << std::endl << std::endl;
            s.displayShoppingCart();
            std::cout << std::endl << "Veuillez sélectionner le nom/id du client, le nom du produit ainsi que la quantité du produit que vous voulez modifier" << std::endl;
            std::cout << "Nom ou Id : "; std::cin >> name_or_id;
            std::cout << "Nom du produit : "; std::cin >> title;
            do
            {
                std::cout << "Quantité souhaitée : "; 
                std::cin >> quantity;
            } while (quantity < 0);
            for(unsigned i = 0; i < s.getClient().size(); ++i)
            {
                for(unsigned j = 0; j < s.getClient().at(i).getShoppingCart().size();  ++j)
                {
                    if((s.getClient().at(i).getName() == name_or_id || s.getClient().at(i).getId() == name_or_id) && s.getClient().at(i).getShoppingCart().at(j).first.getTitle() == title)
                    {
                        s.updateQuantityShoppingCart(s.getClient().at(i),s.getClient().at(i).getShoppingCart().at(j).first,quantity);
                        ok = false;
                    }
                }
            }
            if(ok)
                std::cout << std::endl << "Le nom/id du client,le nom du produit ou la quantité n'est pas correct" << std::endl;
            std::cout << std::endl;
        }
        else
            std::cout << "Il n'y a pour l'instant aucun Client dans le magasin" << std::endl << std::endl;
        break;
    }
}

void Gestion_Orders(Shop& s, int& choice)
{
    bool ok = true;
    std::string name_or_id;
    do
    {
        std::cout << "Veuillez entrer le numéro correspondant à l'option souhaitée" << std::endl;
        std::cin >> choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0);
    switch(choice)
    {
    case 1:
        std::cout << "Vous avez choisi l'ajout d'une commande." << std::endl << std::endl;
        if(s.getClient().size() != 0)
        {
            std::cout << "À quel client souhaitez-vous créer une commande ?" << std::endl << std::endl;
            s.displayClient();
            std::cout << "Nom ou Id : "; std::cin >> name_or_id;
            for(unsigned i = 0; i < s.getClient().size(); ++i)
            {
                if(name_or_id == s.getClient().at(i).getId() || name_or_id == s.getClient().at(i).getName())
                {
                    Order o(s.getClient().at(i));
                    s.addOrder(o);
                    ok = false;
                }
            }
            if(ok)
                std::cout << std::endl << "Le nom/id du client n'est pas correct" << std::endl;
        }
        else
            std::cout << "Il n'y a pour l'instant aucun Client dans le magasin" << std::endl << std::endl;
        break;
    case 2:
        std::cout << "Vous avez choisi l'affichage des commandes validées." << std::endl << std::endl;
        s.displayOrder();
        break;
    case 3:
        std::cout << "Vous avez choisi la validation de commandes." << std::endl << std::endl;
        if(s.getOrder().size() != 0)
        {
            std::cout << "Quelle commande souhaitez-vous valider ?" << std::endl << std::endl;
            for(unsigned i = 0; i < s.getOrder().size(); ++i)
            {
                std::cout << s.getOrder().at(i) << std::endl;
            }
            std::cout << "Nom ou Id du client dont vous voulez valider la commande : "; std::cin >> name_or_id;
            for(unsigned i = 0; i < s.getOrder().size(); ++i)
            {
                if(name_or_id == s.getOrder().at(i).getClient().getId() || name_or_id == s.getOrder().at(i).getClient().getName())
                {
                    s.orderValidate(s.getOrder().at(i));
                    ok = false;
                }
            }
            if(ok)
                std::cout << std::endl << "Le nom/id du client n'est pas correct" << std::endl;
        }
        else
            std::cout << "Il n'y a pour l'instant aucune commande à valider" << std::endl << std::endl;
        break;
    case 4:
        std::cout << "Vous avez choisi les commandes passées par un client." << std::endl << std::endl;
        if(s.getClient().size() != 0)
        {
            std::cout << "De quelle Client voulez-vous voir les commandes ?" << std::endl << std::endl;
            s.displayClient();
            std::cout << "Nom ou Id du client : "; std::cin >> name_or_id;
            std::cout << std::endl;
            for(unsigned i = 0; i < s.getClient().size(); ++i)
            {
                if(name_or_id == s.getClient().at(i).getId() || name_or_id == s.getClient().at(i).getName())
                {
                    s.orderByClient(s.getClient().at(i));
                    ok = false;
                }
            }
            if(ok)
                std::cout << std::endl << "Le nom/id du client n'est pas correct" << std::endl;
        }
        else
            std::cout << "Il n'y a pour l'instant aucun Client dans le magasin" << std::endl << std::endl;
        break;
    }
}

void Gestion_File(Shop& s, int& choice)
{
    //Déclaration d'un flux permettant d'écrire dans le fichier
    std::ofstream monFlux1("Produits.txt");
    std::ofstream monFlux2("Clients.txt");
    std::ofstream monFlux3("Commandes.txt");
    //Déclaration d'un flux permettant de lire le ichier
    std::ifstream monFlux4("Produits.txt");
    std::ifstream monFlux5("Clients.txt");
    std::ifstream monFlux6("Commandes.txt");
    if(monFlux1)    
    {
        for(unsigned i = 0; i < s.getProduct().size(); ++i)
        {
            monFlux1 << s.getProduct().at(i) << std::endl;
        }
        monFlux1.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    if(monFlux2)    
    {
        for(unsigned i = 0; i < s.getClient().size(); ++i)
        {
            monFlux2 << s.getClient().at(i) << std::endl;
        }
        monFlux2.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    if(monFlux3)    
    {
        for(unsigned i = 0; i < s.getOrder().size(); ++i)
        {
            if(s.getOrder().at(i).getStatus() == 1)
            {
                monFlux3 << s.getOrder().at(i) << std::endl;
            }
        }
        monFlux3.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
    int file;
    do
    {
        std::cout << "Veuillez entrer le numéro correspondant à l'option souhaitée" << std::endl;
        std::cin >> choice;
    }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0);
    switch(choice)
    {
    case 1:
        std::cout << "Vous avez choisi la lecture des fichiers." << std::endl << std::endl;
        std::cout << "Quel fichier voulez-vous ouvrir ? Produits (1)   Clients (2)   Commandes (3)" << std::endl << std::endl;
        do
        {
            std::cout << "Veuillez entrer le numéro correspondant au fichier souhaité" << std::endl;
            std::cin >> file;
            std::cout << std::endl;
        }while(file != 1 && file != 2 && file != 3);
        switch(file)
        {
        case 1:
            if(monFlux4)
            {
                std::string ligne;
                while(getline(monFlux4,ligne))
                    std::cout<<ligne<<std::endl;
            }
            else
                std::cout<<"impossible d'ouvrir le fichier" << std::endl;
            break;
        case 2:
            if(monFlux5)
            {
                std::string ligne;
                while(getline(monFlux5,ligne))
                    std::cout<<ligne<<std::endl;
            }
            else
                std::cout<<"impossible d'ouvrir le fichier" << std::endl;
            break;
        case 3:
            if(monFlux6)
            {
                std::string ligne;
                while(getline(monFlux6,ligne))
                    std::cout<<ligne<<std::endl;
            }
            else
                std::cout<<"impossible d'ouvrir le fichier" << std::endl;
            break;
        }
        break; 
    }
}

void Menu(Shop& s)
{
    int init = 0;
    int& choice = init;
    while(choice == 0)
    {
        std::cout << "----------------------------------------------------MENU----------------------------------------------------" << std::endl << std::endl;
        std::cout << "Gestion du Magasin (1)   Gestion des Utilisateurs (2)   Gestion des Commandes (3)   Lecture des fichiers (4)   Quitter le Menu (O)" << std::endl << std::endl;
        do
        {
            std::cout << "Veuillez entrer le numéro correspondant à la gestion souhaitée" << std::endl;
            std::cin >> choice;
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 0);
        switch(choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            std::cout << "Vous avez choisi la gestion du Magasin" << std::endl;
            while(choice != 0)
            {
                std::cout << "------------------------------------------------------------------SOUS-MENU------------------------------------------------------------------" << std::endl << std::endl;
                std::cout << "Ajout d'un produit (1)   Affichage des produits (2)   Affichage d'un produit par son nom (3)   Mise à jour des quantités (4)   Quitter le Sous-Menu (0)" << std::endl << std::endl;
                Gestion_Shop(s,choice);
            }
            break;
        case 2:
            std::cout << "Vous avez choisi la gestion des Utilisateurs" << std::endl;
            while(choice != 0)
            {
                std::cout << "-----------------------------------------------------------------------------------SOUS-MENU-----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
                std::cout << "Ajout d'un utilisateur (1)  Affichage des utilisateurs (2)  Affichage avec nom ou id (3)  Ajout produit (4)  Suppression produit (5)  Modifier la quantité (6)  Quitter le Sous-Menu (0)" << std::endl << std::endl;
                Gestion_Clients(s,choice);
            }
            break;
        case 3:
            std::cout << "Vous avez choisi la gestion des Commandes" << std::endl;
            while(choice != 0)
            {
                std::cout << "------------------------------------------------SOUS-MENU------------------------------------------------" << std::endl << std::endl;
                std::cout << "Ajout d'une commande (1)   Affichage des commandes (2)   Validation de commandes (3)   Commande passé par un Client (4)   Quitter le Sous-Menu (0)" << std::endl << std::endl;
                Gestion_Orders(s,choice);
            }
            break;
        case 4:
            std::cout << "Vous avez choisi la lecture des fichiers" << std::endl;
            while(choice != 0)
            {
                std::cout << "--------------------SOUS-MENU----------------" << std::endl << std::endl;
                std::cout << "Lire les fichiers (1)  Quitter le Sous-Menu (0)" << std::endl << std::endl;
                Gestion_File(s,choice);
            }
            break;
        }
    }
}

int main()
{
    Shop s1;
    Menu(s1);

    return 0;
}
