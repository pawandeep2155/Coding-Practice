import java.util.HashSet;
import java.util.Set;

public class HelloWorld{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HashSet<String> set = new HashSet<String>();
		String current ="";
		System.out.println(findWay("rrlrlr",current, set,0, 0, 1));
	}
	
	
	public static int findWay(String patt, String current,HashSet<String> set,int index, int 			
                                                value, int difference){
		int count = 0;
		if(index == patt.length() && value == difference){
			if(set.contains(current)){
				return 0;
			}else{
				System.out.println(current);
				set.add(current);
				return 1;
			}
		}else if(index == patt.length()){
			return 0;
		}
		
		count += findWay(patt,current,set, index+1, value, difference);
		if(patt.charAt(index)=='r'){
			value++;
			current = current+"r";
		}else{
			value--;
			current = current+"l";

		}
		count += findWay(patt,current,set, index+1, value, difference);
		return count;
	}
}