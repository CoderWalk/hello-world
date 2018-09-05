class Emp// implements Cloneable
{
	int id,sal;
	String name;
	public Emp(int x,String y,int z)
	{
		id=x;
		name=y;
		sal=z;
	}
	public void show()
	{
		System.out.println(id+" "+name+" "+sal);
	}
	public Object clone()throws CloneNotSupportedException
	{
		return super.clone();
	}
}
class CloneDemo
{
	public static void main(String[] arr)throws CloneNotSupportedException
	{
		System.out.println("creating some emp obj...")	;
		Emp e=new Emp(101,"abc",10000);
		Emp f=new Emp(102,"xyz",12000);
		/*if(e instanceof Cloneable)
		System.out.println("yes");
		else
		System.out.println("no");*/
		System.out.println("details of obj to be clone...");
		e.show(); 
		f.show();
		Emp p=(Emp)e.clone();
		Emp q=(Emp)f.clone();
		p.show();
		q.show();
	}
}