基本概念：
    数据是客观事实的符号，表示指所有能输入到计算机中并被计算机程序处理的符号的总称。
    数据元素：数据元素是数据的基本单位。一个学生记录。
    数据项：是组成数据元素、有独立含义、不可分割的最小单位。学生基本信息表。
    数据对象:是相互之间存在一种或多种特定关系的数据元素的集合。换句话说,数据结构是带结构的数据元素的集合。
             结构:就是数据元素之间存在的关系。
    逻辑结构:从逻辑关系上描述数据,它与数据的存储无关,是独立于计算机的。因此数据的逻辑结构可以看做从具体问题抽象
             出来的数学模型
    存储结构:是数据对象在计算机中的存储表示,也成为物理结构
    抽象数据类型:是由用户定义的,表示应用问题的数学模型,以及定义在这个模型上的一组操作的总称。
                具体包括三部分:数据对象,数据对象上关系的集合和对数据对象的基本操作的集合。
    
1. 数据结构
        逻辑结构
            1.1 集合结构 :数据元素属于同一集合的关系外,别无其他关系
            1.2 线性结构 :一对一的关系
            1.3 树结构  :一对多的关系
            1.4 图结构或者网状结构:多对多关系
        也可以分为
            1.1 线性结构:线性表、栈和队列、字符串
            1.2 非线性结构:集合结构、树结构、图结构
        物理结构和存储结构
            顺序存储结构和链式存储结构
2. 算法
        特性:有穷性、确定性、正确性、输入、输出
        评价标准:正确性、健壮性、可读性、高效性
        效率度量:时间复杂度、空间复杂度


线性表
    1. 线性表的定义和特点
        除第一个元素无直接前驱和最后一个元素无直接后继之外,其他每个数据元素都有一个前驱和后继。
    2. 顺序表
        2.1 线性表的顺序表示指的是用一组地址连续的存储单元依次存储线性表的数据元素,
        这种表示也称作线性表的顺序存储结构和顺序映像。也称为这种存储结构的线性表叫做顺序表。
        其特点是:逻辑上相邻的数据元素,其物理次序也是相邻的。
        2.2 线性表中第i+1个数据元素的存储位置loc(ai+1)和第i个数据元素的存储位置loc(ai)满足如下关系
        loc(ai+1)=loc(ai)+l;l:占用l个存储单元
        一般来说,线性表的第i个数据元素ai的存储位置为:
        loc(ai)=loc(a1)+(i-1)*l;
    3. 单链表
        3.1 线性表的链式存储结构的特点是:用一组任意的存储单元存储线性表的数据元素(这组存储单元可以是连续的,也可以是不连续的)
        3.2 区别
            首元结点:首元结点是指链表中存储第一个数据元素a1的结点.
            头结点:头结点是在首元结点之前附设的一个结点,其指针域指向首元结点.头结点的数据域可以不存储任何信息,
                    也可以存储域数据元素类型相同的其他附加信息。例如,当数据元素为整数型时,头结点的数据域可存放该线性表的长度。
            头指针:是指向链表中第一个结点的指针。
                    若链表设有头结点,则头指针所指结点为线性表的头结点;若链表不设头结点,则头指针所指结点为该线性表的首元结点。
        3.3 链表增加头结点的作用
            1. 便于首元结点的处理
            2. 便于空表和非空表的统一处理
    4. 顺序表和链表的比较
            1. 空间性能的比较
                1.1 存储空间的分配
                        顺序表： 预先分配,会导致空间闲置或者溢出
                        链表:动态分配,不会出现存储空间闲置或者溢出现象
                1.2 存储密度的分配
                        顺序表:不用为表示结点间的逻辑关系而额外增加额外的存储开销,存储密度为1
                        链表:需要借助指针来体现元素间的逻辑关系,存储密度小于1
            2. 时间性能的比较
                2.1 存取元素
                        顺序表:随机存取,按位置访问元素的时间复杂度为O(1)
                        链表:顺序存取,按位置访问元素的时间复杂度为O(n)
                    插入、删除
                        顺序表:平均移动约表中的一半元素,时间复杂度为O(n)
                        链表:不需要移动元素,确定插入、删除位置后,时间复杂度为O(1)
    5.适用情况
            1. 顺序表：
                表长变化不大,且能事先确定变化的范围
                很少进行插入或删除操作，经常按元素位置序号访问数据元素
            2. 链表
                长度变化大
                频繁进行插入和删除操作。
    6. 单链表、循环链表、双向链表的比较