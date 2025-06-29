#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <limits>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct BibleVerse {
    string reference;
    string text;
};

void waitForEnter() {
    cout << "Press Enter to continue...\n";
    cin.get();
}


void addSin(vector<string>& sins) {
    cout << "Please enter a sin you'd like to write down: ";
    string sin;
    getline(cin, sin);

    if (sin.empty())
    {
        cout <<"Write a sin that you had commited and feel guilt";
    }

    else{
         sins.push_back(sin);

    }
    
}

void showSins(const vector<string>& sins) {
    if (sins.empty()) {
        cout << "No sins have been added yet." << endl;
    } else {
        cout << "Here are the sins you've written down:\n";
        for (const auto& s : sins) {
            cout << "- " << s << endl;
        }
    }
    waitForEnter();
}

void showforgivenessfromgod() {
    cout << "==================================================\n";
    cout << "          🙏 A Message of Forgiveness:\n";
    cout << "==================================================\n";
    cout << "✨ No matter what sins you've committed,\n";
    cout << "   God will always forgive you, my friend.\n";
    cout << "   Speak with Him. Pray. Believe.\n";
    cout << "   There is always a path back to grace.\n";
    cout << "==================================================\n";
}

void commandments() {
    cout << "\n📕==============================================📕\n";
    cout << "        📖 Bible Verses about COMMANDMENTS\n";
    cout << "📕==============================================📕\n\n";
    waitForEnter();


    vector<string> tenCommandments = {
        "1. No other gods",
        "2. No idols",
        "3. Do not misuse God’s name",
        "4. Keep the Sabbath",
        "5. Honor your father and mother",
        "6. Do not murder",
        "7. Do not commit adultery",
        "8. Do not steal",
        "9. Do not lie",
        "10. Do not covet"
    };

    cout << "📖 *Exodus 20:1–17*\n";
    cout << "The Ten Commandments:\n";
    for (const string& cmd : tenCommandments) {
        cout << cmd << endl;
    }
    cout << endl;
    waitForEnter();

    // Other verses about commandments
    vector<pair<string, string>> verses = {
        { "📖 *John 14:15*", 
          "\"If you love me, keep my commandments.\"" },

        { "📖 *1 John 2:3–4*", 
          "\"We know that we have come to know him if we keep his commands.\"" },

        { "📖 *Deuteronomy 6:6–7*", 
          "\"These commandments that I give you today are to be on your hearts.\"" }
    };

    for (const auto& verse : verses) {
        clearScreen();
        cout << verse.first << "\n";
        cout << verse.second << "\n\n";
        waitForEnter();
    }
}

void goodthing(vector<string>& goodthings) {
    cout << "\n🌼 Write something good you're grateful for: ";
    string gratitude;
    getline(cin, gratitude);

   if (gratitude.empty())
   {
    cout << "Write a gratitude you have";
   }
   else{
    goodthings.push_back(gratitude);
    cout << "🌟 Grateful note recorded.\n";
   }
   
    waitForEnter();
}

void showgoodthing(const vector<string>& goodthings) {
    if (goodthings.empty()) {
        cout << "No good things have been added yet." << endl;
    } else {
        cout << "Here are the good things you've written:\n";
        for (const auto& g : goodthings) {
            cout << "- " << g << endl;
        }
    }
    waitForEnter();
}
void praise() {
    vector<BibleVerse> praiseVerses = {
        {"Psalm 150:6", "Let everything that has breath praise the Lord. Praise the Lord!"},
        {"Hebrews 13:15", "Through Jesus, therefore, let us continually offer to God a sacrifice of praise—\nthe fruit of lips that openly profess his name."},
        {"Psalm 100:4", "Enter his gates with thanksgiving and his courts with praise;\ngive thanks to him and praise his name."},
        {"1 Chronicles 16:34", "Give thanks to the Lord, for he is good;\nhis love endures forever."},
        {"Psalm 103:1–2", "Praise the Lord, my soul;\nall my inmost being, praise his holy name.\nPraise the Lord, my soul,\nand forget not all his benefits."},
        {"Psalm 147:1", "Praise the Lord.\nHow good it is to sing praises to our God,\nhow pleasant and fitting to praise him!"},
        {"Isaiah 25:1", "Lord, you are my God;\nI will exalt you and praise your name,\nfor in perfect faithfulness you have done wonderful things,\nthings planned long ago."}
     
    };

    cout << "\n🎵==============================================🎵\n";
    cout << "           🎶 Bible Verses about PRAISE\n";
    cout << "🎵==============================================🎵\n\n";

    waitForEnter();

    for (const auto& verse : praiseVerses) {
        clearScreen();
        cout << "📖 *" << verse.reference << "*\n";
        cout << "\"" << verse.text << "\"\n\n";
        waitForEnter();
    }
}


void visaSlumpadVers() {
    vector<string> verser = {
          "\n📖 Lamentations 3:22-23\n"
        "\"The steadfast love of the Lord never ceases;\n"
        "his mercies never come to an end;\n"
        "they are new every morning;\n"
        "great is your faithfulness.\"\n",

        "\n📖 Joshua 1:9\n"
        "\"Be strong and courageous.\n"
        "Do not be afraid; do not be discouraged,\n"
        "for the Lord your God will be with you wherever you go.\"\n",

        "\n📖 Psalm 121:1-2\n"
        "\"I lift up my eyes to the hills—\n"
        "where does my help come from?\n"
        "My help comes from the Lord,\n"
        "the Maker of heaven and earth.\"\n",

        "\n📖 Hebrews 13:5\n"
        "\"Never will I leave you;\n"
        "never will I forsake you.\"\n",

        "\n📖 Romans 15:13\n"
        "\"May the God of hope fill you with all joy and peace\n"
        "as you trust in him,\n"
        "so that you may overflow with hope\n"
        "by the power of the Holy Spirit.\"\n",

        "\n📖 1 Peter 5:7\n"
        "\"Cast all your anxiety on him\n"
        "because he cares for you.\"\n",

        "\n📖 John 16:33\n"
        "\"In this world you will have trouble.\n"
        "But take heart!\n"
        "I have overcome the world.\"\n",

        "\n📖 Isaiah 40:31\n"
        "\"But those who hope in the Lord\n"
        "will renew their strength.\n"
        "They will soar on wings like eagles;\n"
        "they will run and not grow weary,\n"
        "they will walk and not be faint.\"\n",

        "\n📖 Psalm 34:18\n"
        "\"The Lord is close to the brokenhearted\n"
        "and saves those who are crushed in spirit.\"\n",

        "\n📖 Deuteronomy 31:6\n"
        "\"Be strong and courageous.\n"
        "Do not be afraid or terrified because of them,\n"
        "for the Lord your God goes with you;\n"
        "he will never leave you nor forsake you.\"\n"
    };
    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % verser.size();
    cout << verser[index] << "\n\n";

}

void godsayingyes() {
    cout << "\n🌟==============================================🌟\n";
    cout << "     🙌 Signs God Is Saying YES to Our Prayers\n";
    cout << "🌟==============================================🌟\n\n";
    waitForEnter();

    // Fruit of the Spirit
    string fruits[] = {
        "love", "joy", "peace", "patience", "kindness",
        "goodness", "faithfulness", "gentleness", "self-control"
    };

    cout << "📖 Galatians 5:22–23\n";
    cout << "---------------------------\n";
    cout << "But the fruit of the Spirit is:\n";
    for (const string& fruit : fruits) {
        cout << "  • " << fruit << endl;
    }
    cout << "\nAgainst such things there is no law.\n\n";
    waitForEnter();


    vector<pair<string, string>> verses = {
        { "📖 Philippians 4:6–7", 
          "🕊️ Do not be anxious about anything,\n"
          "but in everything, by prayer and supplication\n"
          "with thanksgiving, let your requests be made known to God.\n"
          "And the peace of God, which surpasses all understanding,\n"
          "will guard your hearts and minds in Christ Jesus." },

        { "📖 1 Corinthians 14:33", 
          "🌿 For God is not a God of confusion but of peace." },

        { "📖 Romans 15:13 (NIV)", 
          "\"May the God of hope fill you with all joy and peace\n"
          "as you trust in him, so that you may overflow with hope\n"
          "by the power of the Holy Spirit.\"" },

        { "📖 Colossians 3:15 (NIV)", 
          "\"Let the peace of Christ rule in your hearts,\n"
          "since as members of one body you were called to peace.\n"
          "And be thankful.\"" },

        { "📖 Isaiah 26:3 (NIV)", 
          "\"You will keep in perfect peace those whose minds are steadfast,\n"
          "because they trust in you.\"" }
    };

    for (const auto& verse : verses) {
        clearScreen();
        cout << verse.first << "\n";
        cout << "------------------------------\n";
        cout << verse.second << "\n\n";
        waitForEnter();
    }

    // Signs God is saying YES
    vector<string> signs = {
        "✅ Doors open naturally — with peace, not pressure.",
        "✅ You feel inner confirmation through Scripture or prayer.",
        "✅ Wise counsel affirms your direction.",
        "✅ The answer aligns with God's character and Word.",
        "✅ You feel deep peace even if the outcome is uncertain."
    };

    cout << "💡 Practical Signs God Might Be Saying YES:\n";
    cout << "----------------------------------------------\n";
    for (const string& sign : signs) {
        cout << sign << endl;
    }
    cout << endl;
    waitForEnter();
}

void godsayingno() {
    cout << "\n🌧️==============================================🌧️\n";
    cout << "     🙏 Signs God Is Saying NO to Our Prayers\n";
    cout << "🌧️==============================================🌧️\n\n";
    waitForEnter();

    cout << "🛡️ Sometimes God's 'No' is not rejection —\n";
    cout << "it's redirection, protection, or preparation.\n\n";
    waitForEnter();

    vector<pair<string, string>> verses = {
        { "📖 *2 Corinthians 12:8–9*", 
          "\"My grace is sufficient for you,\nfor my power is made perfect in weakness.\"" },

        { "📖 *James 4:3*", 
          "\"You do not receive, because you ask with wrong motives.\"" },

        { "📖 *Isaiah 55:8–9*", 
          "\"My thoughts are not your thoughts,\nneither are your ways my ways,\" declares the Lord." },

        { "📖 *Proverbs 3:5–6*", 
          "\"Trust in the Lord with all your heart\nand lean not on your own understanding.\"" },

        { "📖 *Psalm 84:11*", 
          "\"No good thing does He withhold from those who walk uprightly.\"" },

        { "📖 *Hebrews 12:11*", 
          "\"Later on, discipline produces a harvest of righteousness.\"" },

        { "📖 *Acts 16:6–7*", 
          "\"The Spirit of Jesus would not allow them.\"" },

        { "📖 *Job 1:21*", 
          "\"The Lord gave and the Lord has taken away;\nblessed be the name of the Lord.\"" },

        { "📖 *Deuteronomy 3:26*", 
          "\"Do not speak to me anymore about this matter.\"" }
    };

    for (const auto& verse : verses) {
         clearScreen();
        cout << verse.first << "\n";
        cout << "------------------------------\n";
        cout << verse.second << "\n\n";
        waitForEnter();
    }

    vector<string> closing = {
        "🌧️==============================================🌧️",
        "🕊️ Even when God says NO, He is still good, wise, and faithful.",
        "🛤️ Keep walking with Him — the journey is part of the purpose.",
        "🌧️==============================================🌧️\n"
    };

    for (const string& line : closing) {
        cout << line << endl;
    }
    waitForEnter();
}




void wisdom() {
    cout << "\n📘==============================================📘\n";
    cout << "             💡 Bible Verses about WISDOM\n";
    cout << "📘==============================================📘\n\n";
    waitForEnter();

    vector<pair<string, string>> wisdomVerses = {
        { "📖 *Proverbs 3:13–18*",
          "\"Blessed is the one who finds wisdom,\n"
          "and the one who gets understanding,\n"
          "for the gain from her is better than gain from silver\n"
          "and her profit better than gold.\n"
          "She is more precious than jewels,\n"
          "and nothing you desire can compare with her.\n"
          "Long life is in her right hand;\n"
          "in her left hand are riches and honor.\n"
          "Her ways are ways of pleasantness,\n"
          "and all her paths are peace.\n"
          "She is a tree of life to those who lay hold of her;\n"
          "those who hold her fast are called blessed.\"" },

        { "📖 *James 1:5*",
          "\"If any of you lacks wisdom, let him ask of God,\n"
          "who gives generously to all without reproach,\n"
          "and it will be given to him.\"" },

        { "📖 *Ecclesiastes 7:12*",
          "\"For wisdom is a defense as money is a defense,\n"
          "but the excellence of knowledge is that wisdom gives life\n"
          "to those who have it.\"" },

        { "📖 *Proverbs 1:7*",
          "\"The fear of the Lord is the beginning of knowledge,\n"
          "but fools despise wisdom and instruction.\"" }
    };

    for (const auto& verse : wisdomVerses) {
    clearScreen();
    cout << "📖 Bible Verses about WISDOM\n\n";
    cout << verse.first << "\n";
    cout << verse.second << "\n\n";
    waitForEnter();
}
}



void prophecy() {
    cout << "\n🔮==============================================🔮\n";
    cout << "            📜 Bible Verses about PROPHECY\n";
    cout << "🔮==============================================🔮\n\n";
    waitForEnter();

    vector<pair<string, string>> prophecyVerses = {
        { "📖 *Joel 2:28*",
          "\"And afterward,\n"
          "I will pour out my Spirit on all people.\n"
          "Your sons and daughters will prophesy,\n"
          "your old men will dream dreams,\n"
          "your young men will see visions.\"" },

        { "📖 *1 Corinthians 14:1*",
          "\"Pursue love, and earnestly desire the spiritual gifts,\n"
          "especially that you may prophesy.\"" },

        { "📖 *Revelation 19:10*",
          "\"At this I fell at his feet to worship him. But he said to me,\n"
          "'Don’t do that! I am a fellow servant with you and with your\n"
          "brothers and sisters who hold to the testimony of Jesus.\n"
          "Worship God! For the testimony of Jesus is the spirit of prophecy.'\"" },

        { "📖 *Amos 3:7*",
          "\"Surely the Sovereign Lord does nothing\n"
          "without revealing his plan to his servants the prophets.\"" }
    };

    for (const auto& verse : prophecyVerses) {
         clearScreen();
        cout << verse.first << "\n";
        cout << "------------------------------\n";
        cout << verse.second << "\n\n";
        waitForEnter();
    }
}



void gospels() {
    cout << "\n📕==============================================📕\n";
    cout << "             ✝️ Bible Verses about the GOSPELS\n";
    cout << "📕==============================================📕\n\n";
    waitForEnter();

    vector<pair<string, string>> gospelVerses = {
        { "📖 *John 3:16*",
          "\"For God so loved the world that he gave his one and only Son,\n"
          "that whoever believes in him shall not perish but have eternal life.\"" },

        { "📖 *Mark 1:15*",
          "\"The time has come,\" he said. \"The kingdom of God has come near.\n"
          "Repent and believe the good news!\"" },

        { "📖 *Luke 19:10*",
          "\"For the Son of Man came to seek and to save the lost.\"" },

        { "📖 *Matthew 28:19–20*",
          "\"Therefore go and make disciples of all nations,\n"
          "baptizing them in the name of the Father and of the Son and of the Holy Spirit,\n"
          "and teaching them to obey everything I have commanded you.\n"
          "And surely I am with you always, to the very end of the age.\"" },

        { "📖 *Romans 1:16*",
          "\"For I am not ashamed of the gospel, because it is the power of God\n"
          "that brings salvation to everyone who believes: first to the Jew, then to the Gentile.\"" },

        { "📖 *1 Corinthians 15:3–4*",
          "\"Christ died for our sins according to the Scriptures,\n"
          "that he was buried, that he was raised on the third day\n"
          "according to the Scriptures.\"" }
    };

    for (const auto& verse : gospelVerses) {
         clearScreen();
        cout << verse.first << "\n";
        cout << "------------------------------\n";
        cout << verse.second << "\n\n";

        waitForEnter();
    }
}




void showMenu() {
    cout << "\n══════════════════════════════════════════════════════════════\n";
    cout << "                ✝️  Welcome to the Bible Study            \n";
    cout << "══════════════════════════════════════════════════════════════\n";
    visaSlumpadVers();
    cout << "══════════════════════════════════════════════════════════════\n";
    cout << " 🌟 What would you like to do today?                          \n";
    cout << "══════════════════════════════════════════════════════════════\n";
    cout << "\n1. ✍️  Write down a sin\n\n";
    cout << "2. 📜 Show the sins you've written\n\n";
    cout << "3. 💖 Write down good things you've done\n\n";
    cout << "4. ⚖️  Compare sins with good things\n\n";
    cout << "5. 🌼 Show the good things you've written\n\n";
    cout << "6. 🙌 Signs God is saying YES to our prayers\n\n";
    cout << "7. 🚫 Signs God is saying NO to our prayers\n\n";
    cout << "8. 📖 Bible verses about WISDOM\n\n";
    cout << "9. 🔮 Bible verses about PROPHECY\n\n";
    cout << "10. 🎵 Bible verses about PRAISE\n\n";
    cout << "11. 📘 Bible verses about COMMANDMENTS\n\n";
    cout << "12. 📕 Bible verses about the GOSPELS\n\n";
    cout << "13. 🚪 Exit the Bible Study\n\n";
    cout << "══════════════════════════════════════════════════════════════\n";
}

int main() {
    vector<string> sins;
    vector<string> goodthings;

    int choice;

    do {
        clearScreen();
        showMenu();

        // ✅ Input validation
        string input;
        bool validInput = false;
        do {
            cout << "\n🔢 Enter your choice from the menu (1-14): ";
            getline(cin, input);

            if (!input.empty() && all_of(input.begin(), input.end(), ::isdigit)) {
                choice = stoi(input);
                validInput = true;
            } else {
                cout << "\n⚠️  Invalid input. Please enter a number between 1 and 14.\n";
            }
        } while (!validInput);

        clearScreen();

        cout << "╔══════════════════════════════════════════════════════╗\n";
        cout << "║                🙏 Bible Study Program 🙏              ║\n";
        cout << "╠══════════════════════════════════════════════════════╣\n";

 
        if (choice < 1 || choice > 14) {
           
            cout << "║ ⚠️  Invalid Menu Number (1-14 Only)                  ║\n";
            cout << "╚══════════════════════════════════════════════════════╝\n";
            waitForEnter();
            
            continue;
        }

        switch (choice) {
            case 1:
                cout << "║ ✍️  Add a Sin Entry                                 ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                 clearScreen();
                addSin(sins);
                break;
            case 2:
                cout << "║ 🙇‍♂️  Confess Sins and Receive Forgiveness         ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                  clearScreen();
                showforgivenessfromgod();
                showSins(sins);
             
                break;
            case 3:
                cout << "║ 🌟  Add a Good Deed                                 ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                  clearScreen();
                goodthing(goodthings);
                break;
            case 4:
                cout << "║ 📜  Review Your Sins and Good Deeds                ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                clearScreen();
                showforgivenessfromgod();
                cout << "\n🧾 Your Sins:\n";
                showSins(sins);
                cout << "\n💖 Your Good Deeds:\n";
                showgoodthing(goodthings);
                 
                 
                break;
            case 5:
                cout << "║ 📝  View Good Deeds List                            ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                clearScreen();
                showgoodthing(goodthings);
                  
                break;
            case 6:
                cout << "║ ✅  God Says: YES                                    ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                  clearScreen();
                godsayingyes();
                 
                break;
            case 7:
                cout << "║ ❌  God Says: NO                                     ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                  clearScreen();
                godsayingno();
                break;
            case 8:
                cout << "║ 🧠  Wisdom Verses                                    ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                  clearScreen();
                wisdom();
                break;
            case 9:
                cout << "║ 🔮  Prophecy Verses                                  ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                clearScreen();
                prophecy();
                break;
            case 10:
                cout << "║ 🎶  Praise Verses                                    ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                  clearScreen();
                praise();
                break;
            case 11:
                cout << "║ 📖  Ten Commandments                                 ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                  clearScreen();
                commandments();
                break;
            case 12:
                cout << "║ ✝️  Gospel Teachings                                 ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n\n";
                  clearScreen();
                gospels();
                break;
            case 13:
                cout << "║ 🙌  Thank You for Using the Program                  ║\n";
                cout << "╚══════════════════════════════════════════════════════╝\n";
                
                clearScreen();
                cout << "\n📖 May God bless you abundantly!\n";
                cout << "🙏 May God's peace and wisdom be with you always.\n\n";
                break;
        }

    } while (choice != 13);

    return 0;
}