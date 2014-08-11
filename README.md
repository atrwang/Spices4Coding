Spices4Coding
=============

Note kinds of spices in coding, have a taste and enjoy it!

#### 1.  ValueForKey usage in NSAarray/NSSet 2014年08月11日15:37:05
    UIView* view1 = [UIView new];
    view1.tag = 1;
    
    UIView* view2 = [UIView new];
    view2.tag = 2;
    
    UIView* view3 = [UIView new];
    view3.tag = 2;
 
    NSArray* viewArr = @[view1,view2,view3];
    NSSet* viewSet = [NSSet setWithArray:viewArr];
    
    id  tagsInArr = [viewArr **valueForKey**:@"tag"];
    id  tagsInSet = [viewSet **valueForKey**:@"tag"];
    
	tagsInArr is a array with objects @1,@2,@2
	tagsInSet is a set  with objects:  @1,@2
	
	note: 1. valueForKey can find with keyPath, 2. Set will eliminate the same object
