#进阶2：条件查询
/*
语法：select 查询列表  from 表名 where 筛选条件;
分类：1.按条件表达式筛选  > < =  <>  >=  <=
      2.按逻辑表达式筛选  && ||  !  and or not
      3.模糊查询  like  和通配符（% 任意多个字符  _任意一个字符 ）使用                  
                  between and 包含临界值;两个值不能颠倒位置
                  in( , , )   属于列表中一项,且列表值类型兼容，不支持通配符
                  is null  =和<>不能判断null值,但安全等于<=>可以查询null值和普通值 
*/
# 员工工资大于12000
SELECT 
  * 
FROM
  employees 
WHERE salary > 12000 ;

# 部门编号不等于90的员工名和部门编号
SELECT 
  last_name,
  department_id 
FROM
  employees 
WHERE department_id <> 90 ;  #可以用!=
# 查询工资在10000-20000之间的员工名，工资和奖金
SELECT 
  last_name,
  salary,
  commission_pct 
FROM
  employees 
WHERE salary >= 10000 
  AND salary <= 20000 ;
# 查询部门编号不是在90-110间，或工资高于15000的员工信息
SELECT 
  * 
FROM
  employees 
WHERE NOT (
    department_id >= 90 AND department_id <= 110
  ) 
  OR salary > 15000 ;
  
  
# 查询员工名中包含字符a的信息   like
SELECT 
  * 
FROM
  employees 
WHERE last_name LIKE '%a%' ;

# 查询员工名中第二个字符为_的信息   like
SELECT 
  * 
FROM
  employees 
WHERE last_name LIKE '_$_%' ESCAPE '$';

   
# 查询员工编号在100-120 间员工的信息   between and
SELECT 
  * 
FROM
  employees 
WHERE employee_id BETWEEN 100 
  AND 120 ;
  
  
# 查询员工工种编号是 IT_PROT,AD_VP，AD_PRES中一个的员工名和工种编号   in
SELECT 
  last_name,
  job_id 
FROM
  employees 
WHERE job_id IN ('IT_PROT', 'AD_VP', 'AD_PRES') ;


# 查询没有奖金的员工名和奖金率  is null
SELECT 
  last_name,
  commission_pct 
FROM
  employees 
WHERE commission_pct IS NOT NULL ;


