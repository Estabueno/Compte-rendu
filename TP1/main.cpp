#include "loan.h"
#include "author.h"
#include "library.h"

int main()
{
	Date d1(3, 10, 1906);
	Date d2(35,12,2020);
	Date d3(30,4,1877);
	Date d4(5,12,2022);
	Date d5(23,9,1987);
	Date d6(15,8,1976);
	Date d7(29,10,1675);
	Date d8(43,1,1000);
	Date d9(20,2,2020);
	Date d10(12,5,1964);

    Author a1("098373838", "Jack", "London", Date(12,1,1976));
	Author a2("373838", "Goerge", "Martin", Date(20,9,1948));
	Author a3("0983744658", "Albert", "Camus", Date(7,11,1913));
	Author a4("0687667577", "Joanne", "Rowling", Date(31,7,1965));

	Book b1("Croc-Blanc",a1,French,Love,d1,"1425");
	Book b2("A song of Ice and Fire",a2,English,Love,d2,"7851");
	Book b3("Game of Thrones",a2,English,SF,d3,"42525");
	Book b4("Blood and Fire",a2,French,Historical,d4,"062734");
	Book b5("El principito",a1,Spanish,SF,d5,"936546");
	Book b6("L'Étranger",a3,French,Detective,d6,"72752");
	Book b7("El dia de la muerte",a3,Spanish,Love,d7,"03752");
	Book b8("Le joueur d'échec",a1,German,Historical,d8,"7243637");
	Book b9("Fahrenheit 451",a4,German,SF,d9,"423217");
	Book b10("Harry Potter",a4,English,SF,d10,"562892");

	Reader r1("1620201","Salim","Mansouri");
	Reader r2("902736","Adrien","Jacquet Cretides");
	Reader r3("142673","Paulé","Valayé");
	r3.setName("Paulin");

	Library lib(a1,b1,r1);
	lib.addAuthor(a2);
	lib.addAuthor(a3);
	lib.addAuthor(a4);
	//lib.displayAuthor();

	lib.addBook(b2);
	lib.addBook(b3);
	lib.addBook(b4);
	lib.addBook(b5);
	lib.addBook(b6);
	lib.addBook(b7);
	lib.addBook(b8);
	lib.addBook(b9);
	lib.addBook(b10);
	//lib.displayBook();
	lib.addReader(r2);
	lib.addReader(r3);

	Loan l1(d1,b1,r1);
	lib.loan(l1);
	lib.displayLoan();
	lib.bestReader();

	Loan l2(d4,b4,r2);
	Loan l4(d6,b6,r1);
	lib.loan(l2);
	lib.loan(l2);
	lib.displayLoan();

	lib.loan(l4);
	lib.displayLoan();
	Loan l3(d4,b4,r1);
	lib.loan(l3);
	lib.restore(l1);
	//lib.restore(l1);
	lib.displayLoan();
	lib.restore(l3);
	
	lib.restore(l2);
	lib.displayLoan();
	lib.loan(l2);
	b1.displayLoaner();
	b4.displayLoaner();
	b6.displayLoaner();

	r2.displayLoan();

    std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;
	std::cout << r3 << std::endl;

    std::cout << a1 << std::endl;

    std::cout << b1 << std::endl;

	a2.displayBookAuthor();
	a3.displayBookAuthor();
	lib.displayLoan();

	lib.displayReader();
	std::cout << "Le pourcentage de livre empruntés est de " << lib.percentageBook() << "%" << std::endl;

	lib.bestReader();

	return 0;
}
