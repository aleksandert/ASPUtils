<%@ language="vbscript" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>ASPUtilsTest - Cache</title>
    <style type="text/css">
        #stopwatch {border: 1px solid black;padding:0px}
        #stopwatch td {padding: 5px;}
    </style>
    <script language="jscript" runat="server" >

        function JsCacheSet(i) {

            var item = "from method";

            Cache.Set("js", item);

        }

        function JsCacheGet() {

            var item = Cache("js")
            
            return item;
        }
    

    </script>
</head>
<body>
<%=Now() %><br />
Items: <%=Cache.Count %><br />

<%=Request.ServerVariables("REQUEST_METHOD") %>

<% 
if Request.ServerVariables("REQUEST_METHOD") = "POST" then

    select case Request.Form("action")
        case "set"
            Response.Write "JsCacheSet"
            JsCacheSet(Now())
        case "get"
            Response.Write "JsCacheGet"
            Response.Write(JsCacheGet())
    end select

    

    

end if

%>

<% 
   
    for each key in Cache.Keys
    
        value = Cache(key)

        Response.Write(value & "[" & TypeName(value) & "]<br>")

    next
%>

<form method="post" action="Test.asp">

<input type="radio" name="action" value="set" />Set JS<br />
<input type="radio" name="action" value="get" />Get JS<br />

<br />
<input type="submit" value="Submit"  />

</form>

</body>       
</html>
