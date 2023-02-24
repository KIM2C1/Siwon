import xlsxwriter

# Create a new Excel workbook and add a worksheet
workbook = xlsxwriter.Workbook('example.xlsx')
worksheet = workbook.add_worksheet()

# Write the headers to the first row
worksheet.write(0, 0, "send")
worksheet.write(0, 1, "receive")

# Write data to the second row
worksheet.write(1, 0, "Hello")
worksheet.write(1, 1, "World")

# Close the workbook
workbook.close()