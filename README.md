#Mulch

A Chemistry Stoichiometry C++ Library

![Orange](http://www.arktimes.com/binary/fedc/1305756869-orange.png)

Parses Chemical Equations
Balances Chemical Equations
Does g/mol conversions, etc

This project is currently in development phase, and there are no stable releases available.

###How To Use

Using the mulch library is very simple. You can create a chemical equation by constructing a new ```ChemEquation``` object and supplying a string with the chemical equation.

```
mulch::ChemEquation combustion("CH4 + O2 = H2O + CO2");
```

You can also create a default ChemEquation object and set the equation later on.

```
mulch::ChemEquation combustion;

combustion.setEquation("CH4 + O2 = H2O + CO2");
```

You can then get the equation you just set in string form.

```
string methane = combustion.getEquation();
```

You can then get each compound of the equation packed into a STL vector.

```
vector <string> methaneCompounds = combustion.getCompoundStrings();
```

Want even more data about the compounds, such as the element count, etc? This function will return a vector of structs. Each struct contains data about one compound.

```
vector <mulch::compound> methaneCompounds = combustion.getCompoundData();
```

###Current Plan

Currently there are three repos of Mulch. This is the main repository, and there are two personal repos over @shrimpboyho and @dpwivagg 

There repositories are focused on two seperate aspects of this project.

@shrimpboyho is strictly for parser development

@dpwivagg is strictly for calculator development

Once both parts of the project work, one C++ class will be created and it will be known as the ChemEquation.

###Jobs

There are many jobs availible for those who want to contribute to the growth of this project.

We are currently in need of someone to maintain documentation, as well as someone who is experienced will managing pull requests.

There are future plans to port this library over to JavaScript utilizing Emscripten.

###How To Build

Build at your own risk.

Build using the Code::Blocks IDE. There is a project file in the repository one can open.
