<%@ language="vbscript" EnableSessionState="false" %>
<%
  
    Set Session = SessionManager.Session(false) 
    
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title></title>
</head>
<body>
<%

    Response.Write("SessionId: " & Session.SessionID & "<br>")
    Response.Write("Timeout: " & Session.Timeout & "<br>")

    Response.Write("Last time in session object: " & Session("Time") & "<br>")
    
    Response.Write("Set current time in session object...<br>")
    
    Session("Time") = now()

    Response.Write("New time in session object: " & Session("Time") & "<br>")

%>

</body>
</html>
