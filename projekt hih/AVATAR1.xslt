<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html" indent="yes"/>
  
  <xsl:template match="links/link">
    <xsl:if test="not(position() = last())">
      <li>
        <ul>
        <a>
          <xsl:attribute name="href">
            <xsl:value-of select="@source"/>
          </xsl:attribute>
          <xsl:value-of select="."/>
        </a>
        </ul>
      </li>
    </xsl:if>
  </xsl:template>


 <xsl:template match="/projekt/ksiega/side/team">
  <link rel="stylesheet" href="avatar1.css" type="text/css"/>
    <html>
      <body>
        <xsl:choose>
          <xsl:when test="@leader='Awatar' ">
          <h3>
            Team Awatar <br></br>Rozdział: <xsl:value-of select="ancestor::ksiega[1]/@czesc" /> </h3>
          </xsl:when>
          <xsl:when test="@ leader='Zuko' ">
            <h3>
              Team Zuko <br></br>Rozdział: <xsl:value-of select="ancestor::ksiega[1]/@czesc" />
            </h3>
          </xsl:when>
          <xsl:when test="@leader='Azula' ">
            <h3>
              Team Azula<br></br>Rozdział: <xsl:value-of select="ancestor::ksiega[1]/@czesc" />
          </h3>
          </xsl:when>
          <xsl:when test="@leader='Iroh' ">
            <h3>
              White Lotus <br></br>Rozdział: <xsl:value-of select="ancestor::ksiega[1]/@czesc" />
          </h3>
          </xsl:when>
         
        </xsl:choose>
        <table>
          <tr>
            <th>Imie</th>
            <th>Magia</th>
            <th>Broń</th>
          </tr>
          <xsl:for-each select="postac">
            <tr>
              <td>
                <xsl:value-of select="imie"/>
              </td>
              <td>
                <xsl:value-of select="magia"/>
              </td>
              <td>
                <xsl:value-of select="bron"/>
              </td>
            </tr>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>

  <xsl:template match="links/link">
    <xsl:if test="not(position() = last())">
      <li>
        <a>
          <xsl:attribute name="href">
            <xsl:value-of select="@source"/>
          </xsl:attribute>
          <xsl:value-of select="."/>
        </a>
      </li>
    </xsl:if>
  </xsl:template>
  
   <xsl:template match="ranking">
     <h3><xsl:text>Personal Ranking of </xsl:text>
    <xsl:value-of select="count(odcinek)" /> <xsl:text> ATLA episodes:</xsl:text></h3>
    <xsl:text>&#10;</xsl:text>
    <xsl:apply-templates select="odcinek/@rank">
      <xsl:sort data-type="number" order="descending" />
    </xsl:apply-templates>
    <xsl:text>&#10;</xsl:text>
  </xsl:template>
  
  <xsl:template match="odcinek/@rank">
    <br></br>
    <xsl:apply-templates select=".." />
    <xsl:text> (</xsl:text>
    <xsl:value-of select="." />
    <xsl:text>)&#10;</xsl:text>
  </xsl:template>

  

  
  <xsl:template match="author">
    <link rel="stylesheet" href="avatar1.css" type="text/css"/>
    <html>
      <footer>
      Wykonał
      <xsl:value-of select="name"/><xsl:text> </xsl:text>
      <xsl:value-of select="surname"/><xsl:text> </xsl:text>
      <xsl:value-of select="kierunek"/><xsl:text> </xsl:text>
      <xsl:value-of select="grupaDziekanska"/><xsl:text> </xsl:text>
      <xsl:value-of select="index"/>
      </footer>
    </html>
  </xsl:template>

  <xsl:template match="media/image">
    <img>
      <xsl:attribute name="src">
        <xsl:value-of select="@source"/>
      </xsl:attribute>
      <xsl:attribute name="class">
        right
      </xsl:attribute>
      <xsl:attribute name="ksiega">
        <xsl:value-of select="."/>
      </xsl:attribute>
    </img>
  </xsl:template>

  <xsl:template match="projekt/media/image">
    <img>
      <xsl:attribute name="src">
        <xsl:value-of select="@source"/>
      </xsl:attribute>
      <xsl:attribute name="class">
        right
      </xsl:attribute>
      <xsl:attribute name="title">
        <xsl:value-of select="."/>
      </xsl:attribute>
    </img>
  </xsl:template>

</xsl:stylesheet>
