#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
class BaseBag;
class BaseOpponent;
class BaseKnight;
class ArmyKnights; 
class BaseItem;
class Events;
class KnightAdventure;
class Antidot;
class DragonKnight;
class PaladinKnight;
class LancelotKnight;
class NormalKnight;

 //phoenixdown
enum KnightType{ PALADIN = 0, LANCELOT, DRAGON, NORMAL };
enum ItemType {PHOENIXDOWNI = 1,PHOENIXDOWNII,PHOENIXDOWNIII,PHOENIXDOWNIV,ANTIDOT};


class BaseKnight{// class cha của ArmyKnights
protected:
    int id; // định danh hiệp sĩ
    int hp; // máu hiệp sĩ
    int maxhp; // máu tối đa hiệp sĩ
    int level; // level của hiệp sĩ
    int gil; // tiền của hiệp sĩ
    int antidote; 
    int phoenixdownI; 
    int phoenixdownII;
    int phoenixdownIII;
    int phoenixdownIV;

    BaseBag * bag; // túi đồ của hiệp sĩ
    KnightType knightType; // mã 4 hiệp sĩ đặc biệt
    BaseKnight *nextknight;

public:
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI); // tạo ra đối tượng hiệp sĩ phù hợp
    // hàm thuần ảo
    virtual bool fight(BaseOpponent * opponent) ; // mô tả quá trình giao đấu với Đối thủ , và những cập nhật lên hiệp sĩ trả về true nếu win false nếu thua
    void setid(int) ;
    void sethp(int) ;
    void setmaxhp(int);
    void setlevel(int);
    void setgil(int);
    void setantidote(int);
    void setphoenixdownI(int);
    void setnItem_max(int);
    void setInsert(BaseItem*);
    void setPhoenixdownII(int);
    void setPhoenixdownIII(int);
    void setPhoenixdownIV(int);
    int getid();
    int gethp();
    int getmaxhp();
    int getlevel();
    int getgil();
    int getantidote();
    int getphoenixdownI();
    int getphoenixdownII();
    int getphoenixdownIII();
    int getphoenixdownIV();
    void setType(KnightType);
    int getType();
    bool is_Lancelot(int);
    bool is_Dragon(int);
    bool is_Paladin(int);
    bool handleWhenHPDown();
    BaseBag* getbag();
    string toString() const;
    ~BaseKnight();
};



class BaseItem{ // class con: class trừu tượng (maybe class đa hình) -> vật phẩm
public:
    ItemType itemtype;
    BaseItem* next = NULL;
    virtual bool canUse ( BaseKnight * knight ) = 0; // trả về true nếu có thể sử dụng false nếu ko thể sử dụng
    virtual void use ( BaseKnight * knight ) = 0;  //  sử dụng vật phẩm: thay đổi các thông số của hiệp sĩ
};


class BaseOpponent{
    protected:
        int levelO;
        int Type_opponent;
        int gil;
        int base_dame;
        int OpponentType;
       
    public:

    int get_levelO();
    void set_levelO(int i, int num_event);
    int get_Type();
    int get_Base_Damage();
    int get_gil();
};// class trừu tương: biểu diên thông tin của một đối thủ
// class này là class cha của các class MadBear, Bandit, LordLupin, Elf, Troll, Tornbery, QueenOfCards, NinaDeRings, DurianGarden, OmegaWeapon, Hades
enum OpponentType {Type_MadBear = 1, Type_Bandit, Type_LordLupin, Type_Elf, Type_Troll, Type_Tornbery, Type_QueenOfCards, Type_NinaDeRings, Type_DurianGarden, Type_OmegaWeapon, Type_Hades};
class MadBear :public BaseOpponent{
    private:
  
    public:
    MadBear(int i, int num_event);
    ~MadBear();
};
class Bandit:public BaseOpponent{
        //  private:
        // int gil;
        // int base_dame;
        // int OpponentType;
         public:
    Bandit(int i, int eventcode);
    ~Bandit();
       
};
class LordLupin :public BaseOpponent{
        // private:
        // int gil;
        // int base_dame;
        // int OpponentType;
         public:
    LordLupin(int i, int eventcode);
    ~LordLupin();
      
};
class Elf:public BaseOpponent{
    //   private:
    //     int gil;
    //     int base_dame;
    //     int levelO;
    //     int OpponentType;
         public:
    Elf(int i, int eventcode);
    ~Elf();
};
class Troll:public BaseOpponent{
    //  private:
    //     int gil;
    //     int base_dame;
    //     int levelO;
    //     int OpponentType;
         public:
    Troll(int i, int eventcode);
    ~Troll();
};
class Tornbery :public BaseOpponent{
    //  private:
    //     int gil;
    //     int base_dame;
    //     int levelO;
    //     int OpponentType;
     public:
    Tornbery(int i, int eventcode);
    ~Tornbery();
};
class QueenOfCards :public BaseOpponent{
    //  private:
    //     int gil;
    //     int base_dame;
    //     int levelO;
    //     int OpponentType;
     public:
    QueenOfCards(int i, int eventcode);
    ~QueenOfCards();
};
class NinaDeRings :public BaseOpponent{
    //  private:
    //     int gil;
    //     int base_dame;
    //     int levelO;
    //     int OpponentType;
     public:
    NinaDeRings(int i, int eventcode);
    ~NinaDeRings();
};
class DurianGarden :public BaseOpponent{
    //  private:
    //     int gil;
    //     int base_dame;
    //     int levelO;
    //     int OpponentType;
     public:
    DurianGarden(int i, int eventcode);
    ~DurianGarden();
};
class OmegaWeapon :public BaseOpponent{
    //  private:
    //     int gil;
    //     int base_dame;
    //     int levelO;
    //     int OpponentType;
     public:
    OmegaWeapon(int i, int eventcode);
    ~OmegaWeapon();
};
class Hades :public BaseOpponent{
    //  private:
    //     int gil;
    //     int base_dame;
    //     int levelO;
    //     int OpponentType;
     public:
    Hades(int i, int eventcode);
    ~Hades();
};







class DragonKnight:public BaseKnight{
    private:
        int x;
    public:

};
class Node
{
    public:
    BaseKnight data;
    Node *next;
};
typedef struct Node* node;


class ArmyKnights { // class con biểu diễn thông tin cho đội quân hiệp sĩ
    private:
        int nKnight;
        BaseKnight *ArmyKnight;

public:
    bool Shield = false, Spear = false, Hair = false, Sword = false, win_Omega = false, win_Hades = false;
    Node* head = nullptr;
    Node* tail = nullptr;
    ArmyKnights (const string & file_armyknights); // chứa tên file mô tả thông tin cho đội quân và khởi tạo một mảng các hiệp sĩ từ dữ liệu file đọc vào                     // đọc id từ 1-> hết, hiệp sĩ ở vị trí cuối sẽ là hiệp sĩ giao tranh với các đối thủ và cũng là hs nhặt vật phẩm
    bool adventure (Events * events); // mô tả quá trình đội quân đi qua từng sự kiện, true nếu win false nếu thua sự kiện đó
    int count() const; // trả về số lượng hiệp sĩ hiện tại của đội quân
    BaseKnight * lastKnight() const; // trỏ đến hiệp sĩ cuối cùng trong đội quân, nếu ko còn hiệp sĩ nào thì trả về NULL
    bool hasPaladinShield() const; // kiếm tra xem có khiên Paladin ko?
    bool hasLancelotSpear() const;  // kiếm tra xem có giáo Lancelot ko?
    bool hasGuinevereHair() const;  // kiếm tra xem có tóc Guinever ko?
    bool hasExcaliburSword() const; // kiếm tra xem có gươm Excalibur ko?
    void prize_gil(BaseOpponent *);
    void printInfo() const; // in ra thông tin của đội quân
    void printResult(bool win) const;
    void deleteFirst_knight();
    void deleteMiddle(node &,int);
    bool fightUltimecia();
    ~ArmyKnights();

};

//-----------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------

class Events { // class con
private:
    int nEvent;
    int *Eventt;
public:
    Events(const string &);
    int count() const;  // hàm trả về số lượng sự kiện
    int get(int i) const; // hàm trả về mã sự kiện ở vị trí thứ i
    ~Events();
};


//---------------------------------------------------------------------------------

class KnightAdventure { // class 
private:
    ArmyKnights * armyKnights; 
    Events * events; // 

public:
    KnightAdventure();
    void loadArmyKnights(const string &);
    // nhận vào tham số kiểu string chứa file mô tả thông tin trong Đội quân hiệp sĩ
    void loadEvents(const string &); //  nhận vào 1 tham số kiểu string chứa file mô tả thông tin cho các sự kiên.Khởi tạo đối tượng Events (là một thuộc tính của class) từ file được cung cấp.
    void run(); /*  không có tham số, mô tả quá trình Đội quân Hiệp sĩ đi qua các sự kiện. Cuối mỗi sự
                    kiện cần in ra thông tin của Đội quân sử dụng printInfo() của class ArmyKnights. Sau
                    sự kiện cuối cùng, gọi hàm printResult với thông số truyền vào là true nếu Đội quân
                    Hiệp sĩ chiến thắng Ultimecia, hoặc false nếu Đội quân bị bại trận.*/
    ~KnightAdventure(); // TODO:
};

//---------------------------------------------------//
class Antidot : public BaseItem{
    public:
    bool canUse(BaseKnight*knight);
    void use (BaseKnight * knight);
};
class PhoenixdownI : public BaseItem{
    public:
    PhoenixdownI(){
        this->itemtype = PHOENIXDOWNI;
    }
    bool canUse(BaseKnight*knight);
    void use (BaseKnight * knight);
};
class PhoenixdownII : public BaseItem{
    public:
    PhoenixdownII(){
        this->itemtype = PHOENIXDOWNII;
    }
    bool canUse(BaseKnight*knight);
    void use (BaseKnight * knight);
};
class PhoenixdownIII : public BaseItem{
    public:
    PhoenixdownIII(){
        this->itemtype = PHOENIXDOWNIII;
    }
    bool canUse(BaseKnight*knight);
    void use (BaseKnight * knight);
};
class PhoenixdownIV : public BaseItem{

    public:
    PhoenixdownIV(){
        this->itemtype = PHOENIXDOWNIV;
    }
    bool canUse(BaseKnight*knight);
    void use (BaseKnight * knight);
};

//---------------------------- Base Item ----------------------------------//



//------------------------------- Base Bag ------------------------------//

class BaseBag { // class cha
protected:
    int nItem_now = 0;
    int nIteam_max;
    BaseItem *ptr = NULL;
public:
    virtual bool insertFirst(BaseItem * item); // hàm ảo: trả về true nếu vật phẩm đó có thể thêm vào túi đò ngược lại false
    virtual BaseItem * get(ItemType itemType);// hàm ảo: trả về con trỏ đến một đối tượng biểu diễn cho vật phẩm đầu tiên, nếu ko thấy thì trả về NULL, khi trả về có cùng kiểu thì vật phẩm sẽ được sử dụng và xóa khỏi linked list
                                                    // cách xóa là đổi đến đầu danh sách liên kết và xóa node đầu danh sách, tìm thì duyệt từ đầu danh sách liên kết đến cuối danh sách liên kết
    virtual string toString() const; //  hàm ảo: trả về chuỗi string cho đối tượng BaseIteam: có định dạng Bag[count = <c>;<list_items>]
    void set_nItem_max(int n);
    void deleteFirst();
    BaseItem* getptr();
    void convert(ItemType);
    bool UseItem(ItemType itemType, BaseKnight *knight){
        BaseItem* itemUse = get(itemType);
        if(itemUse){
            convert(itemType);
            itemUse->canUse(knight);
            deleteFirst();
            return true;
        }
        return false;
    }
    int getnItem_now();
    void setnItem_now(int);
    ~BaseBag();
};                                   //<c>: là số lượng items
                                      // <list_item>: là một chuỗi biểu diễn tên các vật phẩm từ đầu đến cuối linked list 
                                      // khởi tạo constructor nhận 2 tham chiếu đầu vào là số phoenixdownI và số antidot hiệp sĩ mang theo 
                                      // thêm phoenixdownI vào linked list trước rồi mới thêm antidote vào linked sau, nhưng mà phải thêm là thêm ở đầu linked list


#endif // __KNIGHT2_H__