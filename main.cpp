#include<iostream> //basic c++ input/output library
#include<fstream> // file IO library
#include<string> // string library
#include<vector> //vector library
//can add more #includes if need more libraries

using namespace std;

//global variables:
int year = 0;

//classes:
class Species
{
public:
	string name;
	int reprAge; //what age will the organism be mature enough to produce offspring
	int deathAge; // what age will the organism die (if it is still alive) getting to an old age?
	int startMass; //what is the mass the organism is born?
	int masstoNotDie; //what is the amount of mass increased every year?
	vector<Species> predators; //what organisms will eat this species?
	vector<Species> prey; //what organisms will this species eat?
};

class Organism
{
public:
	Organism(Species vName); // constructor

	float currentAge;
	Species speciesN;
	float currentMass;
};

vector<Organism> org; //Would it be better to have an array with a set limit? That way it is easier to have organisms die &
//"delete" them (unless there is a vector method that does this automatically that I'm forgetting?)
vector<Species> spec;

Organism::Organism(Species vName)
{
	//cout << "Organism being created and adding to vector....\n"; //change to file io later
	speciesN = vName;
}
//method declarations:

void oneYear();

int main()
{
	cout << "How many species do you want to have?: ";
	int species;
	cin >> species;

	for(unsigned int i = 0; i < species; i++)
	{
		Species names;

		cout << "What is the name species #" << i+1 << "?: ";
		string name;
		cin >> name;
		names.name = name;

		cout << "How many organisms are present of given species?: ";
		int numOrganism;
		cin >> numOrganism;

		cout << "What is the starting mass of all the organisms of the given species?: ";
		int mass;
		cin >> mass;
		names.startMass = mass;

		cout << "How much increase of mass is needed for the organism to stay alive?: ";
		int alive;
		cin >> alive;
		names.masstoNotDie = alive;

		spec.push_back(names);

		for(unsigned int i = 0; i < numOrganism; i++)
		{
			Organism organism(names);
			organism.currentAge = 0;
			organism.currentMass = organism.speciesN.startMass;
			org.push_back(organism);
		}

		cout << "All " << names.name << "s starting at age 0" << endl;

		cout << "At what age will the organisms of the species specified be mature enough to reproduce?: ";
		int repAge;
		cin >> repAge;
		names.reprAge = repAge;

		cout << "At what age will the organisms of the species specified die, if it is able to reach that age?: ";
		int deathAge;
		cin >> deathAge;
		names.deathAge = deathAge;
	}

	string choice = "a";
	while(choice[0] != 'z') // loop to stay in program, z to quit (unless you want it to be 'q')
	{
		cout << "Please choose one of the following options:" << endl;
		cout << "(a) - Advance one year" << endl;
		cout << "(b) - Advance five years" << endl;
		cout << "(f) - List out number of each species" << endl;
		cout << "(g) - List out all organisms alive at present" << endl;
		//cout << "(h) - there will be more things we need to do later
		cout << "(z) - Quit" << endl;

		cin >> choice;

		switch(choice[0])
		{
		case 'a':
			{
				//in development
				for(unsigned int i = 0; i < org.size(); i++)
				{
					org[i].currentAge+= 1;
				}
				oneYear();

				break;
			}

		case 'b':
			{
				//in development
				for(unsigned int i = 0; i < org.size(); i++)
				{
					org[i].currentAge+= 5;
				}
				for(int i = 0; i < 5; i++) oneYear();

				break;
			}

		case 'f':
			{
				//checking for number of each species by name
				string name = org[0].speciesN.name;
				int counter = 1;

				org::iterator iter;

				for(iter = org.being + 1 ; i != org.end; i++)
				{
					if(name.compare(*iter.speciesN.name) != 0)
					{
						name = *iter.speciesN.name;

					}
				}

			}

		case 'g':
			{
				//printing each species
				for(unsigned int i = 0; i < org.size(); i++)
				{
					cout << "Name: " << org[i].speciesN.name << ", Age: " << org[i].currentAge << endl;
				}

				break;
			}

		case 'z': break;

		default:
			{
				cout << "Not a valid option...\n";
				break;
			}
		}
	}


	return 0;
}

//method bodies:

void oneYear()
{
	//in development
	for(int i = 0; i < org.size(); i++)
	{
		int massreq = org[i].speciesN.masstoNotDie; //mass required not to die
			//will add later the death of species
		int temp1 = org[i].speciesN.prey.size();
		Species *most = new Species[temp1];
		
		for(unsigned int i = 0; i < temp1; i++)
		{
			for(unsigned int j = i; j < temp1; j++)
			{
				//in development
			}
		}
	}
	//in development


	year++;
}
