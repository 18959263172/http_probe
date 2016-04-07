/*
 * @author

 */
class Result_Json_Base
{
	int Like;
	int Share;
	char Content[300];
	char	PostDateTime[300];
	char	User[300];
};
/*
 * @author
 */
enum hp_result_type {
	HPSELECTORTYPE_NONE            = -1,
	FACEBOOK           = 0,
	TWITTER           = 1,
	YOUTUBE = 2,
};
/*
 * @author
 */
typedef class Result_All
{
public:
	char *docbuf;
	enum hp_result_type type;
	class Result_Json_Base Result;
}Presult;

/*
 * @author
 */
class FaceBook_CommentList
{
	char User[200];
	char PostDateTime[200];
	char Content[300];
	int like;
	int hare;
	struct CommentList* comment_list; //评价的评价
};

class  Youtube_CommentList
{
	char User[200];
	char PostDateTime[200];
	char Content[300];
	int like;
	int hare;
	struct  CommentList_Youtube *comment_list;
};


class Facebook_Out_Post :Result_Json_Base
{
	char Link[100];
	char PicLink[200];
	char VideoLink[200];
	char IsForward[200];
	int Comment;
	struct CommentList *comment_list;
};

class Twitter_Out_Post :Result_Json_Base
{
	char CrawlDateTime[50];
	char Link[100];
	char PicLink[200];
	char VideoLink[300];
	int IsForward;
	int Comment;
	struct CommentList *comment_list;
};

class Youtube_Out_Post :Result_Json_Base
{
	char Subscription[200];
	int Link;
	int PlayTimes;
	int Comment;
	struct  CommentList_Youtube *comment_list;
};

int out_test_json(char *file_path);
int output_type_decide();
