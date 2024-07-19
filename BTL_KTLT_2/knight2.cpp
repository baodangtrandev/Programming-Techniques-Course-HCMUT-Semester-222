#include "knight2.h"

/* * * BEGIN implementation of class BaseBag * * */

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
BaseKnight::~BaseKnight(){
    delete bag;
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50,'-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

/* * * END implementation of class KnightAdventure * * */
// ---------------------------- Class Event ---------------------
// Construtor

int Events::count() const{
    return nEvent;
}

int Events::get(int i) const {
    return Eventt[i];
}
Events::Events(const string &file_Events){
    ifstream rEvent(file_Events);
    rEvent >> nEvent;
    Eventt = new int[nEvent];
    for (int i = 0; i < nEvent; i++)
    {
        rEvent >> Eventt[i];
        //cout << Eventt[i] << " ";
    }
    rEvent.close();  
}
 Events::~Events(){
        delete [] Eventt;
    }
//---------------------------------- Base Knight ----------------------------------
    // BaseKnight *BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
    // {
    //     BaseKnight *knight = new BaseKnight;
    //     knight->id=id;
    //     knight->maxhp = maxhp;
    //     knight->level = level;
    //     knight->gil = gil;
    //     knight->antidote = antidote;
    //     knight->phoenixdownI = phoenixdownI;
    //     return knight;
    // }
void BaseKnight::setid(int id) {
    this->id = id;
}
void BaseKnight::setlevel(int level){
    this->level = level;
}
void BaseKnight::sethp(int hp) {
    this->hp = hp;
}
void BaseKnight::setmaxhp(int maxhp) {
    this-> maxhp = maxhp;
}
void BaseKnight::setgil(int gil) {
    this->gil = gil;
}
void BaseKnight::setantidote(int antidote) {
    this->antidote = antidote;
}
void BaseKnight::setphoenixdownI(int phoenixdownI){
    this->phoenixdownI = phoenixdownI;
}
void BaseKnight::setPhoenixdownII(int phoenixdownII){
    this->phoenixdownII = phoenixdownII;
}
void BaseKnight::setPhoenixdownIII(int phoenixdownIII){
    this->phoenixdownIII = phoenixdownIII;
}
void BaseKnight::setPhoenixdownIV(int phoenixdownIV){
    this->phoenixdownIV = phoenixdownIV;
}
int BaseKnight::getid(){return this->id;}
int BaseKnight::gethp(){return this->hp;}
int BaseKnight::getlevel(){return this->level;}
int BaseKnight::getmaxhp(){return this->maxhp;}
int BaseKnight::getgil(){return this->gil;}
int BaseKnight::getantidote(){return this->antidote;}
int BaseKnight::getphoenixdownI(){return this->phoenixdownI;}
int BaseKnight::getphoenixdownII(){return this->phoenixdownII;}
int BaseKnight::getphoenixdownIII(){return this->phoenixdownIII;}
int BaseKnight::getphoenixdownIV(){return this->phoenixdownIV;}
BaseBag* BaseKnight::getbag(){return this->bag;}
void BaseKnight::setType(KnightType Type){
    this->knightType = Type;
}
int BaseKnight::getType(){
    return knightType;
}

bool BaseKnight::is_Lancelot(int maxhp){
    if(maxhp == 888) return true;
    else return false;
}
bool BaseKnight::is_Dragon(int hp){
    if (hp >= 100 && hp <= 999)
    {
        int a,b,c;
        a = hp%10;
        b = (hp/10)%10;
        c = hp/100;
        if(a*b*c == 0){return 0;}
        else if(a*a == b*b + c*c||b*b == a*a + c*c || c*c == a*a + b*b){return 1;}
        else return 0;
    }
    else return 0;   
}

bool BaseKnight::is_Paladin(int hp){
    for (int i = 2; i <= sqrt(hp); i++)
    {
        if (hp%i == 0)
        {
            return 0;
        }
        
    }
    return hp>1;  
}

void BaseKnight::setnItem_max(int nItem_max){
    //cout << "check 1";
    this->bag = new BaseBag;
    this->bag->set_nItem_max(nItem_max);
    //cout << "check 2";
    
}
void BaseKnight::setInsert(BaseItem *item){
    //cout << "check 1";
    this->bag->insertFirst(item);
    //cout << "check 2";
}



// ---------------------------------- ArmyKnight -----------------------------

bool ArmyKnights::fightUltimecia(){

    int hpUltimecia = 5000;
    node temp = head;
    node special_temp = head;
    int temp_Knight = nKnight;
    while (temp != NULL)
    {
        if (temp->data.getType() == NORMAL)
        {
            // cout << temp->data.getid() << endl;
            // cout << hpUltimecia << endl;
            // cout << "Normal" << endl;
            temp = temp->next;
        }
        else if (temp->data.getType() == LANCELOT)
        {
            int damage = temp->data.getlevel()*temp->data.gethp()*0.05f;
            hpUltimecia -= damage;
            if (hpUltimecia <= 0)
            {
                return true;
                cout <<"WIn";
            }
            // cout << temp->data.getid() << endl;
            // cout << hpUltimecia << endl;
            // cout << "lance" << endl;
            deleteMiddle(head,temp->data.getid());
           // special_temp = special_temp->next;
            temp = temp->next;
            
        }
        else if (temp->data.getType() == PALADIN)
        {
            int damage = temp->data.getlevel()*temp->data.gethp()*0.06f;
            hpUltimecia -= damage;
            if (hpUltimecia <= 0)
            {
                return true;
                cout <<"WIn";
            }
            // cout << temp->data.getid() << endl;
            // cout << hpUltimecia << endl;
            // cout <<"paladin" << endl;
            deleteMiddle(head,temp->data.getid());
           // special_temp = special_temp->next;
            temp = temp->next;
        }
        else if (temp->data.getType() == DRAGON)
        {
            int damage = temp->data.getlevel()*temp->data.gethp()*0.075f;
            hpUltimecia -= damage;
            if (hpUltimecia <= 0)
            {
                return true;
                cout <<"WIn";
            }
            // cout << temp->data.getid() << endl;
            // cout <<"dragon" << endl;
            // cout << hpUltimecia << endl;
            deleteMiddle(head,temp->data.getid());
           // special_temp = special_temp->next;
            temp = temp->next;
            
        }
        
    }
    
    return false;
}

ArmyKnights::~ArmyKnights(){
    Node *p=head;
    while(head!=NULL)
    {p=head;
    head=head->next;
    delete p;}
    
}

void ArmyKnights::prize_gil(BaseOpponent *oponent){
    int take_gil = 0;
    if (oponent->get_Type()== Type_QueenOfCards)
    {
        take_gil = lastKnight()->getgil();
    }
    else{
        take_gil  = oponent->get_gil();
    }
//cout<<oponent->get_Type()<<" "<<take_gil<<"tien danh qua";

            node ptr = head;
    while (ptr != NULL && take_gil > 0)
            {
                int gil_now = ptr->data.getgil();
                if (take_gil + gil_now > 999)
                {
                    take_gil = take_gil + gil_now - 999;
                    gil_now = 999;
                    ptr->data.setgil(gil_now);
                    ptr = ptr->next;
                }
                else {ptr->data.setgil(gil_now+take_gil);
                    take_gil = 0;
                }
                
            }
}

ArmyKnights::ArmyKnights(const string & file_armyknights){
    ifstream rArmyKnight(file_armyknights);
    rArmyKnight >> nKnight;
    for (int i = 0; i < nKnight; i++)
    {   node ptr = new Node();
        int maxhp,level,gil,antidote,phoenixdownI;
        rArmyKnight>> maxhp >> level >> phoenixdownI >> gil >> antidote;
        //cout << maxhp << level << phoenixdownI << gil << antidote;
        //BaseKnight *knight = BaseKnight::create(i+1,maxhp,level,gil,antidote,phoenixdownI);
        //cout << "hello" << endl;
        ptr->data.setid(i+1);
        ptr->data.setmaxhp(maxhp);
        ptr->data.sethp(maxhp);
        ptr->data.setlevel(level);
        ptr->data.setgil(gil);
        ptr->data.setantidote(antidote);
        ptr->data.setphoenixdownI(phoenixdownI);
        ptr->next = nullptr;
        if(this->head == nullptr ){
            this->head =ptr;
            this->tail = ptr;
        }
        else{
            ptr->next = this->head;
            this->head = ptr;
        
        }
        if(ptr->data.is_Lancelot(maxhp)){
            ptr->data.setType(LANCELOT);
            ptr->data.setnItem_max(16);
        }
        else if(ptr->data.is_Dragon(maxhp)){
            ptr->data.setType(DRAGON);
            ptr->data.setnItem_max(14);
        }
        else if(ptr->data.is_Paladin(maxhp)){
            ptr->data.setType(PALADIN);
            ptr->data.setnItem_max(1500);
        }
        else{
            ptr->data.setType(NORMAL);
            ptr->data.setnItem_max(19);
        }
        for (int i = 0; i < phoenixdownI; i++)
        {
            //cout << "check";
            PhoenixdownI *x = new PhoenixdownI;
            x->itemtype = PHOENIXDOWNI;
            
            //cout << "oke\n";
            ptr->data.setInsert(x);
            //cout << "oke\n";
        }
        if(ptr->data.getType() != DRAGON ){
            for (int i = 0; i < antidote; i++)
            {
            Antidot *x = new Antidot;
            x->itemtype = ANTIDOT;
            ptr->data.setInsert(x);
            }
        }
        
        
    }
        //cout << this->head << endl;
        
    rArmyKnight.close();
    
}

void KnightAdventure::loadEvents(const string & file_events)
{
    //cout << "hehe";
    events = new Events(file_events);
}

  void KnightAdventure::loadArmyKnights(const string & file_armyknights){
   // cout << "hi";
    armyKnights = new ArmyKnights(file_armyknights);
    //cout << "hixx";
  }

void KnightAdventure::run()
{
    //cout << "hello" << endl;
  //  this->armyKnights->printInfo();
  bool result = this->armyKnights->adventure(events);
  this->armyKnights->printResult(result);
  
}

// ArmyKnights::~ArmyKnights(){
//     for (node ptr = ArmyKnight->head; i < count; i++)
//     {
//         /* code */
//     }
    
// }   


 bool ArmyKnights::adventure (Events * events){
    for(int i=0;i< events->count();i++){
        if(events->get(i)==1){
        BaseOpponent *oponent = new MadBear(i,events->get(i));
        if(ArmyKnights::lastKnight()->fight(oponent)){
            ArmyKnights::prize_gil(oponent);
        }
        else{
            int damage = oponent->get_Base_Damage()*(oponent->get_levelO() - ArmyKnights::lastKnight()->getlevel());
            int hp = ArmyKnights::lastKnight()->gethp() - damage;
            ArmyKnights::lastKnight()->sethp(hp);
            ArmyKnights::lastKnight()->handleWhenHPDown();
            if (lastKnight()->gethp() <= 0)
            {
                //cout << "ádasdasd"<< lastKnight()->getid() << endl;
                this->nKnight--;
                deleteFirst_knight();
                if (this->nKnight == 0)
                {
                    printInfo();
                    return 0;
                }    
            }   
            
        } delete oponent;
        }
        else if(events->get(i)==2){
        BaseOpponent *oponent = new Bandit(i,events->get(i));
        if(ArmyKnights::lastKnight()->fight(oponent)){
            ArmyKnights::prize_gil(oponent);
        }
        else{
            int damage = oponent->get_Base_Damage()*(oponent->get_levelO() - ArmyKnights::lastKnight()->getlevel());
            int hp = ArmyKnights::lastKnight()->gethp() - damage;
            ArmyKnights::lastKnight()->sethp(hp);
            ArmyKnights::lastKnight()->handleWhenHPDown();
            if (lastKnight()->gethp() <= 0)
            {
                //cout << "ádasdasd"<< lastKnight()->getid() << endl;
                this->nKnight--;
                deleteFirst_knight();
                if (this->nKnight == 0)
                {
                    printInfo();
                    return 0;
                }    
            }   
        }delete oponent;
        }
        else if(events->get(i)==3){
        BaseOpponent *oponent = new LordLupin(i,events->get(i));
        if(ArmyKnights::lastKnight()->fight(oponent)){
            ArmyKnights::prize_gil(oponent);
        }
        else{
            int damage = oponent->get_Base_Damage()*(oponent->get_levelO() - ArmyKnights::lastKnight()->getlevel());
            int hp = ArmyKnights::lastKnight()->gethp() - damage;
            ArmyKnights::lastKnight()->sethp(hp);
            ArmyKnights::lastKnight()->handleWhenHPDown();
            if (lastKnight()->gethp() <= 0)
            {
                //cout << "ádasdasd"<< lastKnight()->getid() << endl;
                this->nKnight--;
                deleteFirst_knight();
                if (this->nKnight == 0)
                {
                    printInfo();
                    return 0;
                }    
            }   
        }delete oponent;
        }
        else if(events->get(i)==4){
        BaseOpponent *oponent = new Elf(i,events->get(i));
        if(ArmyKnights::lastKnight()->fight(oponent)){
            ArmyKnights::prize_gil(oponent);
        }
        else{
            int damage = oponent->get_Base_Damage()*(oponent->get_levelO() - ArmyKnights::lastKnight()->getlevel());
            int hp = ArmyKnights::lastKnight()->gethp() - damage;
            ArmyKnights::lastKnight()->sethp(hp);
            ArmyKnights::lastKnight()->handleWhenHPDown();
            if (lastKnight()->gethp() <= 0)
            {
                //cout << "ádasdasd"<< lastKnight()->getid() << endl;
                this->nKnight--;
                deleteFirst_knight();
                if (this->nKnight == 0)
                {
                    printInfo();
                    return 0;
                }    
            }   
        }delete oponent;
        }
        else if(events->get(i)==5){
        BaseOpponent *oponent = new Troll(i,events->get(i));
        if(ArmyKnights::lastKnight()->fight(oponent)){
            ArmyKnights::prize_gil(oponent);
        }
        else{
            int damage = oponent->get_Base_Damage()*(oponent->get_levelO() - ArmyKnights::lastKnight()->getlevel());
            int hp = ArmyKnights::lastKnight()->gethp() - damage;
            ArmyKnights::lastKnight()->sethp(hp);
            ArmyKnights::lastKnight()->handleWhenHPDown();
            if (lastKnight()->gethp() <= 0)
            {
                //cout << "ádasdasd"<< lastKnight()->getid() << endl;
                this->nKnight--;
                deleteFirst_knight();
                if (this->nKnight == 0)
                {
                    printInfo();
                    return 0;
                }    
            }   
        }delete oponent;
        }
        else if(events->get(i)==6){
        BaseOpponent *oponent = new Tornbery(i,events->get(i));
        if(ArmyKnights::lastKnight()->fight(oponent)){
            int level = lastKnight()->getlevel() + 1;
            if(level > 10) level = 10;
            lastKnight()->setlevel(level);
        }
        else{
            if (lastKnight()->getantidote() > 0 && lastKnight()->getType()!= DRAGON)
            {
                lastKnight()->getbag()->convert(ANTIDOT);
                lastKnight()->getbag()->deleteFirst();
                int antidote = lastKnight()->getantidote()-1;
                lastKnight()->setantidote(antidote);
            }
            else if (ArmyKnights::lastKnight()->getType() != DRAGON)
            {
                BaseItem *p = lastKnight()->getbag()->getptr();
                int hp = ArmyKnights::lastKnight()->gethp() - 10;
                ArmyKnights::lastKnight()->sethp(hp);
                for (int i = 0; i < 3; i++)
                {
                    lastKnight()->getbag()->deleteFirst(); 
                }
                lastKnight()->handleWhenHPDown();
            }
            
        }delete oponent;
        }
        else if(events->get(i)==7){
        BaseOpponent *oponent = new QueenOfCards(i,events->get(i));
        if(ArmyKnights::lastKnight()->fight(oponent)){
            prize_gil(oponent);
        }
        else if (lastKnight()->getType() == PALADIN)
        {}
        else{
           // cout << lastKnight()->getlevel() << "  " << oponent->get_levelO() << endl;
            int gil = lastKnight()->getgil()/2;
            lastKnight()->setgil(gil);
            //cout << lastKnight()->getgil()<< endl;
        } delete oponent;
        }
        else if(events->get(i)==8){
        BaseOpponent *oponent = new NinaDeRings(i,events->get(i));
            if (lastKnight()->getType() == PALADIN)
            {
                int hp = lastKnight()->gethp() + lastKnight()->getmaxhp()/5;
                lastKnight()->sethp(hp);
            }
            else if (lastKnight()->getgil() < 50){}
            else if (lastKnight()->gethp() < lastKnight()->getmaxhp()/3)
            {
                int gil = lastKnight()->getgil()-50;
                lastKnight()->setgil(gil);
                int hp = lastKnight()->gethp() + lastKnight()->getmaxhp()/5;
                lastKnight()->sethp(hp);
            }  delete oponent;     
        }
        else if(events->get(i)==9){
        BaseOpponent *oponent = new DurianGarden(i,events->get(i));
            lastKnight()->sethp(lastKnight()->getmaxhp());
            delete oponent;
        }
        else if(events->get(i)==10){
            if(win_Omega){} else{
        BaseOpponent *oponent = new OmegaWeapon(i,events->get(i));
        if(ArmyKnights::lastKnight()->fight(oponent)){
            lastKnight()->setlevel(10);
            lastKnight()->setgil(999);
            win_Omega = true;
        }
        else{
            lastKnight()->sethp(0);
            lastKnight()->handleWhenHPDown();
            if (lastKnight()->gethp() <= 0)
            {
                //cout << "ádasdasd"<< lastKnight()->getid() << endl;
                this->nKnight--;
                deleteFirst_knight();
                if (this->nKnight == 0)
                {
                    printInfo();
                    return 0;
                }    
            }   
            }delete oponent;
        }
    }
        else if(events->get(i)==11){
            if (win_Hades){}
            else{
        BaseOpponent *oponent = new Hades(i,events->get(i));
        if(ArmyKnights::lastKnight()->fight(oponent)){
            Shield = true;
            win_Hades = true;
            //cout<<"danh thang has";
        }
        else{
            lastKnight()->sethp(0);
            lastKnight()->handleWhenHPDown();
            if (lastKnight()->gethp() <= 0)
            {
                //cout << "ádasdasd"<< lastKnight()->getid() << endl;
                this->nKnight--;
                deleteFirst_knight();
                if (this->nKnight == 0)
                {
                    printInfo();
                    return 0;
                }    
            }    
        }delete oponent;
        }
        }
        else if(events->get(i)==112 || events->get(i) == 113 || events->get(i) == 114){
            if (events->get(i) == 112)
            {
                BaseItem *x = new PhoenixdownII;
                lastKnight()->getbag()->insertFirst(x);
                lastKnight()->setPhoenixdownII(lastKnight()->getphoenixdownII()+1);
                
            }
            else  if (events->get(i) == 113)
            {
                BaseItem *x = new PhoenixdownIII;
                lastKnight()->getbag()->insertFirst(x);
                lastKnight()->setPhoenixdownIII(lastKnight()->getphoenixdownIII()+1);
            }
            else  if (events->get(i) == 114)
            {
                BaseItem *x = new PhoenixdownIV;
                lastKnight()->getbag()->insertFirst(x);
                lastKnight()->setPhoenixdownIV(lastKnight()->getphoenixdownIV()+1);
            }
        }
        else if (events->get(i) == 95 || events->get(i) == 96 || events->get(i) == 97)
        {
            if (events->get(i) == 95)
            {
                Shield = true;
                hasPaladinShield();
            }
            else if(events->get(i) == 96){
                Spear = true;
                hasLancelotSpear();
            }
            else if (events->get(i) == 97)
            {
                Hair = true;
                hasGuinevereHair();
            }
        }
        else if (events->get(i) == 98)
        {
            if (hasPaladinShield()&&hasLancelotSpear()&&hasGuinevereHair())
            {
                Sword = true;
                hasExcaliburSword();
            }   
        }
        else if (events->get(i) == 99)
        {
            if (hasExcaliburSword())
            {
                printInfo();
                return true;
            }
            else if (!hasPaladinShield()||!hasLancelotSpear()||!hasGuinevereHair())
            {
                nKnight = 0;
            }
            else
            {
                if(!fightUltimecia()){
                    nKnight = 0;
                }
            }
        }
        
       // cout<<i<<'\n';
        printInfo();
        
        
    }
    if(this->count() <= 0)
    return 0;
    else return 1;
    }

//---------------------------------- Base Item -----------------------//
bool Antidot::canUse(BaseKnight * knight){
   return 0;
}

void Antidot::use (BaseKnight * knight){
    knight->setantidote(knight->getantidote()-1);
}

void PhoenixdownI::use (BaseKnight * knight){
    knight->setphoenixdownI(knight->getphoenixdownI()-1);
    knight->sethp(knight->getmaxhp());
}
void PhoenixdownII::use (BaseKnight * knight){
    knight->setPhoenixdownII(knight->getphoenixdownII()-1);
    knight->sethp(knight->getmaxhp());
}
void PhoenixdownIII::use (BaseKnight * knight){
    knight->setPhoenixdownIII(knight->getphoenixdownIII()-1);
    if(knight->gethp()<=0){
    knight->sethp(knight->getmaxhp()/3); }
    else knight->sethp(knight->gethp()+ knight->getmaxhp()/4);
}
void PhoenixdownIV::use (BaseKnight * knight){
    knight->setPhoenixdownIV(knight->getphoenixdownIV()-1);
    if(knight->gethp()<=0){
    knight->sethp(knight->getmaxhp()/2);}
    else knight->sethp(knight->gethp()+ knight->getmaxhp()/5);
}


bool PhoenixdownI::canUse(BaseKnight * knight){
   // cout<<"chay tpoi phou\n";
    if ( knight->gethp() <= 0)
    {
        
        use(knight);
        return 1;
    }
    else return 0;
}
bool PhoenixdownII::canUse(BaseKnight * knight){
    if (knight->getphoenixdownII() > 0 && knight->gethp() <= knight->getmaxhp()/4)
    {
        use(knight);
        return 1;
    }
    else return 0;
}
bool PhoenixdownIII::canUse(BaseKnight * knight){
    if (knight->getphoenixdownIII() > 0 && knight->gethp() <= knight->getmaxhp()/3)
    {
        use(knight);
        return 1;
    }
    else return 0;
}
bool PhoenixdownIV::canUse(BaseKnight * knight){
    if (knight->getphoenixdownIV() > 0 && knight->gethp() <= knight->getmaxhp()/2)
    {
        use(knight);
        return 1;
    }
    else return 0;
}
void BaseBag::set_nItem_max(int n)
{
   // cout << "check 3" << endl;
    this->nIteam_max = n;
    //cout << "check 4";
}

int BaseBag::getnItem_now(){
    return nItem_now;
}

void BaseBag::setnItem_now(int x){
    this->nItem_now = x;
}

//------------------------- Base Knight -----------------------------//
bool BaseKnight::fight(BaseOpponent * opponent){
    if ((knightType == LANCELOT || knightType == PALADIN )&& opponent->get_Type() <= 5)
    {
        //cout <<"1";
        return true;
    }
    else if(knightType == DRAGON && opponent->get_Type() == Type_Tornbery){
       // cout << "2";
        return true;
    }
    else if(((this->gethp() == this->getmaxhp()&& this->getlevel() == 10)||knightType == DRAGON)&& opponent->get_Type() == Type_OmegaWeapon){
       // cout <<"3";
        return true;
    }
    else if(opponent->get_Type() == Type_OmegaWeapon){
       // cout << "4";
        return false;
    }
    else if((this->getlevel() == 10 || (knightType == PALADIN && this->getlevel()>= 8))&&opponent->get_Type() == Type_Hades){
      // cout<<"danh thanh bjdbjd";
        return true;
    }
    else if(opponent->get_Type() == Type_Hades){
        //cout<<"danh thua hasdes";
        return false;
    }
    else if(this->getlevel() >= opponent->get_levelO()){
        //cout <<"5";
        return true;
    }
    else if(this->getlevel()< opponent->get_levelO())
    {
        //cout << "6";
        return false;
    }
    else{ //cout << "7";
        return false;}
}

bool BaseKnight::handleWhenHPDown(){
    BaseItem *p = bag->getptr();
    while (p != NULL)
    {
        //cout<<p->itemtype<<'\n';
        if (!p->canUse(this))
        {
           p = p->next;
        }
        else{
            //cout << "da su dung"<<p->itemtype<<'\n';
           // cout << this->gethp() << endl;
            bag->convert(p->itemtype);
            // BaseItem *x=bag->getptr();
            // cout<<x;
            //cout<<bag->getptr();
           bag->deleteFirst();
            return true;
        }
    }
    if (this->hp <= 0 && this->gil >= 100)
    {
        this->hp = this->maxhp / 2;
        this->gil -= 100;
        return true;
    }
    if (this->hp > 0)
    {
        return 1;
    }
    else return false;
    
}

//--------------------------------KnightAdventure---------------------------//



bool ArmyKnights::hasPaladinShield() const{
    return Shield;
}
bool ArmyKnights::hasLancelotSpear() const{
    return Spear;
}
bool ArmyKnights::hasGuinevereHair() const{
    return Hair;
}
bool ArmyKnights::hasExcaliburSword() const{
    return Sword;
}
KnightAdventure::~KnightAdventure(){
    delete events;
    delete armyKnights;
}
int ArmyKnights::count() const{
    return nKnight;
}
BaseKnight* ArmyKnights::lastKnight() const{
    if (&head->data == nullptr)
    {
        return nullptr;
    }
    else return &head->data;   
}

void ArmyKnights::deleteFirst_knight(){
    if(head == NULL) return;
    Node *p = head;
    head = head->next;
    delete p;
}
void ArmyKnights::deleteMiddle(node &temp, int pos){
    if (pos <= 0|| pos > nKnight){ return;}
    node before = NULL;
    node after = temp;
    for (int i = nKnight; i > pos; i--)
    {
        before = after;
        after = after->next;
    }
    if (before == NULL)
    {
        temp = temp->next;
    }else before->next = after->next;
    nKnight--;
}


//----------------------------- Base Opponent -------------------//

int BaseOpponent::get_levelO(){
    return this->levelO;
}

void BaseOpponent::set_levelO(int i, int num_event){
    this->levelO = (i + num_event)%10 + 1;
}

int BaseOpponent::get_Type()
{
    return OpponentType;
}

int BaseOpponent::get_Base_Damage(){
    return this->base_dame;
}
int BaseOpponent::get_gil(){
    return this->gil;
}



MadBear::MadBear(int i, int num_event)
{
this->gil=100;
this-> OpponentType = Type_MadBear;
this->base_dame=10;
this->set_levelO(i,num_event);
}
Bandit::Bandit(int i, int num_event)
{
this->gil=150;
this-> OpponentType = Type_Bandit;
this->base_dame=15;
this->set_levelO(i,num_event);
}
LordLupin::LordLupin(int i,int num_event)
{
this->gil=450;
this-> OpponentType = Type_LordLupin;
this->base_dame=45;
this->set_levelO(i,num_event);
}
Elf::Elf(int i,int num_event)
{
this->gil=750;
this-> OpponentType = Type_Elf;
this->base_dame=75;
this->set_levelO(i,num_event);
}
Troll::Troll(int i,int num_event)
{
this->gil=800;
this-> OpponentType = Type_Troll;
this->base_dame=95;
this->set_levelO(i,num_event);
}
Tornbery::Tornbery(int i, int num_event){
    this->OpponentType = Type_Tornbery;
    this->set_levelO(i,num_event);
}
QueenOfCards::QueenOfCards(int i, int num_event){
    this->OpponentType = Type_QueenOfCards;
    this->set_levelO(i,num_event);
}
NinaDeRings::NinaDeRings(int i, int num_event){
    this->OpponentType = Type_NinaDeRings;
    this->set_levelO(i,num_event);
}

DurianGarden::DurianGarden(int i, int num_event){
    this->OpponentType = Type_DurianGarden;
}
OmegaWeapon::OmegaWeapon(int i, int num_event){
    this->OpponentType = Type_OmegaWeapon;
}
Hades::Hades(int i, int num_event){
    this->OpponentType = Type_Hades;
}



//---------------------------- Base Bag --------------------------//

bool BaseBag::insertFirst(BaseItem * item){
    
    
    if(nIteam_max>nItem_now)
    {
    if (ptr == NULL)
    {
        ptr = item;
        nItem_now++;
    }
    else{
    item->next=ptr;
    ptr=item;
    nItem_now++;}
    return 1;
    }
    return 0;
}

BaseItem *BaseBag::get(ItemType itemType){
  BaseItem *temp=ptr;
  while(temp!=NULL&&temp->itemtype != itemType){
    temp = temp->next;
  }
  return temp; 
}
// hieenj thucjw ham doi cho va ham xoa first.
void BaseBag::deleteFirst(){
   
    if(ptr == NULL) return;
    BaseItem *p = ptr;
   // cout<<ptr->itemtype<<"kjsbjk\n";
    ptr = ptr->next;
    nItem_now--;
    delete p;
}

BaseItem* BaseBag::getptr(){
    return ptr;
}

void BaseBag::convert(ItemType itemType){
    BaseItem *temp_before = NULL;
    BaseItem *temp_after = ptr;
    BaseItem *temp_second = ptr->next;
    if (ptr->next == NULL)
    {
        return;
    }
    while (temp_after->itemtype != itemType && temp_after->next != NULL)
    {
        temp_before = temp_after;
        temp_after = temp_after->next;
    }
    if (temp_before == NULL)
    {
        return;
    }
    else if(ptr->next->itemtype == itemType){
        ptr->next = temp_second->next;
        temp_second->next = ptr;
        ptr = temp_second;
    }
    else{
        temp_before->next = ptr;
        ptr->next = temp_after->next;
        temp_after->next = temp_second;
        ptr = temp_after;
    }
    
}

string BaseBag::toString() const{
    string s;
    BaseItem *temp = ptr;
    string list_item = "";
    if(ptr!=NULL)
    {
    while (temp->next != NULL)
    {
        if (temp->itemtype == ANTIDOT)
        {
            list_item += "Antidote,";
        }
        else if(temp->itemtype == PHOENIXDOWNI){
            list_item += "PhoenixI,";
        }
        else if(temp->itemtype == PHOENIXDOWNII){
            list_item += "PhoenixII,";
        }
        else if(temp->itemtype == PHOENIXDOWNIII){
            list_item += "PhoenixIII,";;
        }
        else if(temp->itemtype == PHOENIXDOWNIV){
            list_item += "PhoenixIV,";
        } 
        temp = temp->next;
    }
    if (temp->itemtype == ANTIDOT)
        {
            list_item += "Antidote";
        }
        else if(temp->itemtype == PHOENIXDOWNI){
            list_item += "PhoenixI";
        }
        else if(temp->itemtype == PHOENIXDOWNII){
            list_item += "PhoenixII";
        }
        else if(temp->itemtype == PHOENIXDOWNIII){
            list_item += "PhoenixIII";;
        }
        else if(temp->itemtype == PHOENIXDOWNIV){
            list_item += "PhoenixIV";
        }
    }
    s = "Bag[count=" + to_string(nItem_now) + ";" + list_item +"]";
    return s;
}

BaseBag::~BaseBag(){
    while (ptr!= NULL)
    {
        BaseItem *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    nItem_now = 0;    
}

